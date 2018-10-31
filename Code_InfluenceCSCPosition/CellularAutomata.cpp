// main driving program

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include <fstream>
#include <stdlib.h>     /* atof */

// Header files containg class decleartion, function definitiDon't redeclare variables with the same name as the parameterons
#include "CellularAutomata.h"
#include "PropertiesOfBiologicalCell.h"
#include "PropertiesOfExtraCellularMatrixSite.h"
#include "Constructors.h"
#include "GettersSetters.h"
#include "SaveResultsInFile.h"
#include "Update.h"
#include "SetupParameter.h"
#include "LoadState.h"

// 10      20       50      100     200     300     400     500   1000
//Zone1: 0.0003   0.0006   0.0015  0.003   0.006   0.009   0.012   0.015 0.03
//Zone1/2: 500:  0.006
//Zone1/2/3: 500:  0.004
#define CSCCount 500
#define ProbabilityOfplacement 0.0024
CellularAutomata CA[ROWS_IN_CELLULAR_AUTOMATA_WITH_BUFFER][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER];            //Setting dimensions with padding
                                            // Default constructor called on creation of two dimension array of computation cell
                                            // Default set to ECM Sites type
int main()
 {
 	long int i;              // Iterators
 	long int j;

 	int k;              // Iterator used to initialise identity of each cell

 	// Default values of properties of Biological cell and ECM Site

 	int identity = 0;

 	int type = 0;

 	float age = 0;
	float stiffness = 0.5;
	float divisionRate = 0.5;
	int size = 1;
	float contractility = 0.5;
	float invasiveness = 0.5;
	float degradationPotential = 0.5;
	int sensingRadius = 1;

	float fiberDensity = 5;
	float crossLinking = 0.5;

	double randomNumber;

    setUpParameters( &ALPHA, &BETA, &GAMMA, &STATE_OF_FIBER_DENSITY_FOR_CSC_OR_TAC_TO_REPLICATE,
                     &STATE_OF_FIBER_DENSITY_FOR_BIOLOGICAL_CELL_TO_MOVE, &FIBERDENSITY, &DOUBLINGTIME,
                     &SIMULATION_STEPS, &MU, &SIGMA, &LAMBDA );

    cout << "\n Values Read\n"
         << "\n ALPHA " << ALPHA
         << "\n BETA " << BETA
         << "\n GAMMA " << GAMMA
         << "\n STATE_OF_FIBER_DENSITY_FOR_CSC_OR_TAC_TO_REPLICATE " << STATE_OF_FIBER_DENSITY_FOR_CSC_OR_TAC_TO_REPLICATE
         << "\n STATE_OF_FIBER_DENSITY_FOR_BIOLOGICAL_CELL_TO_MOVE " << STATE_OF_FIBER_DENSITY_FOR_BIOLOGICAL_CELL_TO_MOVE
         << "\n FIBERDENSITY " << FIBERDENSITY
         << "\n DOUBLINGTIME " << DOUBLINGTIME
         << "\n SIMULATION_STEPS " << SIMULATION_STEPS
         << "\n MOTILITYPOTENTIAL MU " << MU
         << "\n FRACTION_OF_ES_WITH_FIBERS SIGMA " << SIGMA
         << "\n DEGRADATION LAMBDA " << LAMBDA;

	srand (time(NULL));                     // Initialise random number generator


 	k=1;                                    // Set Identity for each cell
        long int csc_count = 0;

 	for( i=CELLULAR_AUTOMATA_ROW_START; i<= CELLULAR_AUTOMATA_ROW_END; i++ )
     {
        for ( j=CELLULAR_AUTOMATA_COLUMN_START; j<= CELLULAR_AUTOMATA_COLUMN_END ; j++ )
         {
            CA[i][j].setIdentity(k++);

               CA[i][j].resetESProperties();
               CA[i][j].resetBiologicalCellProperties();
	 

/*****   Take value from loaded state **************************/
	  double r = ((double)(rand()%100000))/100000.0;
	//Zone1: ( i>= 111 && i<=289 ) && ( j>=111 && j<=289 )
        //Zone 1 and Zone2:  i>= 74 && i<=326 ) && ( j>=74 && j<=326 )
	//Z1, Z2 and Z3: ( i>= 45 && i<=355 ) && ( j>=45 && j<=355 )
        //Z1/2/3/4: ( i>= 21 && i<=379 ) && ( j>=21 && j<=379 )
        //Z1/2/3/4/5: No condition for i and  j
	  if( ( i>= 21 && i<=379 ) && ( j>=21 && j<=379 ) && (r<=ProbabilityOfplacement) && (csc_count <= CSCCount))	    
            {
	            CA[i][j].setBiologicalCellProperties(CSC, 0, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 1);
 		    csc_count ++;
	    }
/*****   Take value from loaded state **************************/

            else
             {
                CA[i][j].resetESProperties();
                CA[i][j].setType(ES);

                   randomNumber =  (double)(rand()%10000)/10000.0;	

                   if( randomNumber < SIGMA )
                     {
                       CA[i][j].setESProperties( ES, FIBERDENSITY, 0.5 );
                     }
                   else
                     {
                       CA[i][j].resetESProperties();
                     }


             }

         }
     }

	cout << "\n Size Of Int" << sizeof(int) << endl;
	cout << "\n Size Of Cellular Automata Object CA[0][0]" << sizeof(CA[0][0]) << endl;
	cout << "\n Size Of Cellular Automata Objects " << sizeof(CA) << endl;



    cout << "\n Calling update( CA ); ";

	update( CA );

 	return(0);
 }
