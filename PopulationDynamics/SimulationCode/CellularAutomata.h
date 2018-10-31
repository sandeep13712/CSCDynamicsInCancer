// Optimize File Write function

// Concept of Database - normalize functions
// break it to atomic functions
// Get Properties , Set Properties in GettersSetters.h

// class of Cellular Automata - containing properties of Biological Cell and ECM Sites - in files
//   PropertiesOfBiologicalCellInNeighbourhood.h PropertiesOfExtraCellularMatrixSiteInNeighbourhood.h

// Neighbourhood of a cell as 8 Adjacency

// Check linking options in Dev C++
// In function definition - undefined reference to static variable , linker error -o

// generate state function

// Fiber Density Going Negative - checked

using namespace std;

// Dimensions of cellular automata
#define ROWS 200
#define COLUMNS 200

#define CELLULAR_AUTOMATA_ROW_START 2
#define CELLULAR_AUTOMATA_ROW_END ROWS+1

#define CELLULAR_AUTOMATA_COLUMN_START 2
#define CELLULAR_AUTOMATA_COLUMN_END COLUMNS+1

#define ROWS_IN_CELLULAR_AUTOMATA_WITH_BUFFER ROWS+4

#define COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER COLUMNS+4



// number of time the simulations has to be run

// include as global parameters

#define ES 0	    // type 0 - ECM site or ES
#define CSC 1		// type 1 - Cancer Stem Cell
#define TAC 2		// type 2 - Transient Amplifying Cells
#define TDC 3		// type 3 - Terminally Differentiated Cell

double ALPHA;	// Probability ( 0.25, 0.50, 0.75 )
int BETA;   	// Rounds of Amplification and Not Age ( 1 5 10 )
int GAMMA;  	// Maximum Age ( 150 )
int STATE_OF_FIBER_DENSITY_FOR_CSC_OR_TAC_TO_REPLICATE; // ( 0 )
int STATE_OF_FIBER_DENSITY_FOR_BIOLOGICAL_CELL_TO_MOVE; // ( 0 )

double FIBERDENSITY;   // ( 0 to 10 )

int DOUBLINGTIME;   // ( 50 )

int SIMULATION_STEPS;   // ( 2000 ) , Till 10000 for specific , peculiar cases

// int MOTILITYPOTENTIAL;  // ( -1, 2 ) equivalent to non motile and motile respectivels , new as MU
double MU;                 //  Probability of movement ,  1.0 will move , 0 will not move

// double FRACTION_OF_ES_WITH_FIBERS;  //  ( 0.25 0.50 0.75 ) , Now using SIGMA
double SIGMA;

// if 0 false
// bool DEGRADATION;   // ture for degradation, false for without degradation , now LAMBDA
double LAMBDA;




class CellularAutomata
 {
 	//class variables

 	private:
	// Variables to set dimensions of Cellular Automata

//	static int rows;            // rows for number of rows
// 	static int columns;         // columns for number of columns

 	// dimensions - rows * columns number of computational cells
 	// static to create only one copy of varaibles rows and columns

	int identity;               // Each cell is assigned identity

	static int id;              // static , integer to generate sequential numbers , may not be useful as we are using boundary cells

	static double numberOfFibersDegradedByBC;         // static , integer to save count of fibers Degraded by BC

	static double numberOfFibersReplacedByBC;         // static , integer to save count of fibers replaced by BC


	static double numberOfFibersDegradedByCSC;         // static , integer to save count of fibers Degraded by CSC

    static double numberOfFibersReplacedByCSC;         // static , integer to save count of fibers replaced by CSC


	static double numberOfFibersDegradedByTAC;         // static , integer to save count of fibers Degraded by TAC

	static double numberOfFibersReplacedByTAC;         // static , integer to save count of fibers replaced by TAC


	static double numberOfFibersDegradedByTDC;         // static , integer to save count of fibers degraded by TDC

	static double numberOfFibersReplacedByTDC;         // static , integer to save count of fibers degraded by TDC

	//Variable to identify if Computational Cell is a Biological Cell or ECM Site

 	// type set to 0 - considered as ECM site , not a Biological Cell

 	// Following are Types of Biological Cells
 	// type set to 1 - CSC Cancer Stem Cell
 	// type set to 2 - TAC Transient Amplifying Cells
	// type set to 3 - TDC Terminally Differentiated Cell

	int type;	//{ 0, 1, 2, 3 }


 	//Properties of Biological Cell

	float age;                            // Age of Biological cell

 	float stiffness;                    // Stiffness of Biological Cell - (0,1) , how wasy it is to move => remove obstacles

 	float divisionRate;                 // Division Rate also known as Doubling Time of  Biological Cell - (0,1)

 	int size;                           // Size of the Biological Cell - starting with assumption size = 1 , one Biological Cell occupies only one Computational Cell

 	float contractility;                // Contractility of the Biological Cell - (0,1)

 	float invasiveness;                 // Invasiveness also known as Migration Potential of the Biological Cell

 	float fiberDegradationPotential;         // Fiber Degradation Potential of the Biological Cell or potential capacity to degrade ECM

 	// Sensing Radius of the Biological Cell - starting with assumption Sensing Radius = 1
 	// Biological Cell is able to sense one neighbour
 	int sensingRadius;

	int remainingRoundsOfAmplification;

	int beta;


 	//Properties of ECM Site

 	float fiberDensity;                   // Fiber Density of ECM Site - (0,10) , number of fiber per cell area

 	float crossLinking;                 // Cross Linking of ECM Site - (0,1) , amount of crossing in fibers


 	public:

 	// Class having extended properties of Biological Cell In Neighbourhood
 	friend class PropertiesOfBiologicalCellInNeighbourhood;

 	// Class having extended properties of Extra Cellular Matrix Site In Neighbourhood
 	friend class PropertiesOfExtraCellularMatrixSiteInNeighbourhood;

 	// Update function , that checks properties and makes appropriate cell state change call
 	void friend update( CellularAutomata[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER] );



 	void friend setUpParameters( double *, int *, int *, int *,int *, int *, int *,int *, int *, double *, double * );

 	const friend char* getfield(char* , int );

 	// Constructors

 	// Constructor - assign default values to Biological Cell and ECM Site
 	CellularAutomata();

 	//int type, float age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, int sensingRadius , float fiberDensity, float crossLinking
 	CellularAutomata( int , float, float , float , int , float , float , float , int , float , float );

 	// Constructor - assign user defined values to Biological Cell
 	//int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, int sensingRadius
 	CellularAutomata( int , float, float , float , int , float , float , float , int );


 	// Parameterisied Constructor setting only ECM site properties
 	// parameters -
	// int type, float fiberDensity, float crossLinking
	CellularAutomata( int , float , float );

 	//get and set Functions

	static int getRows();

	static void setRows(int);

	static int getColumns();

	static void setColumns(int);


	static double getNumberOfFibersDegradedByBC();

	static void setNumberOfFibersDegradedByBC( double );

    static double getNumberOfFibersReplacedByBC();

    static void setNumberOfFibersReplacedByBC( double );


	static double getNumberOfFibersDegradedByCSC();

	static void setNumberOfFibersDegradedByCSC( double );

    static double getNumberOfFibersReplacedByCSC();

    static void setNumberOfFibersReplacedByCSC( double );


	static double getNumberOfFibersDegradedByTAC();

	static void setNumberOfFibersDegradedByTAC( double );

    static double getNumberOfFibersReplacedByTAC();

    static void setNumberOfFibersReplacedByTAC( double );


    static double getNumberOfFibersDegradedByTDC();

    static void setNumberOfFibersDegradedByTDC( double );

    static double getNumberOfFibersReplacedByTDC();

    static void setNumberOfFibersReplacedByTDC( double );


	int getIdentity();

	void setIdentity(int );

	int getType();

	void setType(int );

	float getAge();

	void setAge( float );

	float getStiffness();

	void setStiffness( float );

	float getDivisionRate( );

	void setDivisionRate( float  );

	int getSize();

	void setSize( int  );

	float getContractility();

	void setContractility( float  );

	void setInvasiveness( float  );

	float getInvasiveness();

	void setFiberDegradationPotential( float );

	float getFiberDegradationPotential();

    float friend calculateFiberDegradationPotential(int);

	int getSensingRadius();

	void setSensingRadius( int  );

	int getRemainingRoundsOfAmplification();

	void setRemainingRoundsOfAmplification(int);

	int getBeta();

	void setBeta(int);

	float getFiberDensity();

	void setFiberDensity( float  );

	float getCrossLinking();

	void setCrossLinking( float );


	// type testers , return type is boolean

	bool isBiologicalCell();            // returns TRUE if Computational cell is Biological Cell
                                        // returns FALSE if Computational cell is not Biological Cell

 	bool isES();                        // returns TRUE if Computational cell is Extra Cellular Matrix Site
                                        // returns FALSE if Computational cell is not Extra Cellular Matrix Site

	bool isCancerStemCell();            // returns TRUE if Computational cell is Cancer Stem Cell

	bool isTransientAmplifyingCell();   // returns TRUE if Computational cell is Transient Amplifying Cell

	bool isTerminallyDifferentiatedCell();  // returns TRUE if Computational cell is Cancer Stem Cell


    // set user defined values to Biological Cell

	//CellularAutomata CA[][12] , int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, int sensingRadius , int fiberDensity, float crossLinking
	void setProperties(CellularAutomata[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER], int , float, float , float , int , float , float , float , int, float , float );

 	//int type, float age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, int sensingRadius
 	void setBiologicalCellProperties( int , float, float , float , int , float , float , float , int );

 	void setESProperties( int , float , float );       	// set user user defined values to ECM Site
                                                        //int type, int fiberDensity, float crossLinking

	void resetBiologicalCellProperties();               // function to set properties of Computational Cell	- now as BiologicalCell

	void resetESProperties();                           // function to set properties of Computational Cell	- now as ECM Site

	void updateDivisionRate(int);                       // Update Division Rate of Biological Cell
                                                        // parameter Total Number Of ES In Neighbourhood

	void updateStiffness( float, int );                 // Update Stiffness of Biological Cell
                                                        // parameter Sum Of Cross Linking In Neighbourhood ,  Total Number Of ES In Neighbourhood

	void updateFiberDegradationPotential( float );           // Update Degradation Potential of Biological Cell
                                                        // parameter Sum Of Fiber Density In Neighbourhood

	void updateFiberDensity( float, float );       // Update Fiber Density of ECM Site
                                                        // parameter present Fiber Density, Average Of Degradation Potential Of BC In Neighbourhood

	void writeResultsToFile(CellularAutomata[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER], int);                               	// write results of Cellular Automata  into files for cell property

	void createResultsFile();

	void incrementAge();                                                            // Increment age of Biological Cell by a unit

	void incrementAge( float );                                                       // Increment age of Biological Cell by a quantity passed as parameter

	void moveCell( CellularAutomata * );

	// Update state of Transient Amplifying Cells to Terminally Differentiated Cells, condition to cell age and BETA
	// parameter CellularAutomata * CA , reference to one random free neighbour cell , whose state may change
	void updateStateOfTransientAmplifyingCell( CellularAutomata *, bool);

	// Update state of Terminally Differentiated Cell to ECM Site, condition to cell age and GAMMA
	void updateStateOfTerminallyDifferentiatedCell( );

	// Update state / Division of Cancer Stem Cell to Transient Amplifying Cell or Cancer Stem Cell
	// condition to ALPHA and availability of free neighbour
	// parameter CellularAutomata * CA , reference to one random free neighbour cell , whose state may change
	void updateStateOfCancerStemCell( CellularAutomata * );

    void friend inRandomFindESInNeighbourhood( CellularAutomata[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER], int, int, double, int *, int *, bool *, int, int y);

 };


// This is required so the compiler has a place for the static variable
// int CellularAutomata::rows=0;
// int CellularAutomata::columns=0;
 int CellularAutomata::id=1;

 double CellularAutomata::numberOfFibersDegradedByBC = 0;

 double CellularAutomata::numberOfFibersReplacedByBC = 0;


 double CellularAutomata::numberOfFibersDegradedByCSC = 0;

 double CellularAutomata::numberOfFibersReplacedByCSC = 0;


 double CellularAutomata::numberOfFibersDegradedByTAC = 0;

 double CellularAutomata::numberOfFibersReplacedByTAC = 0;


 double CellularAutomata::numberOfFibersDegradedByTDC = 0;

 double CellularAutomata::numberOfFibersReplacedByTDC = 0;

	//CellularAutomata CA[][12] , int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, int sensingRadius , int fiberDensity, float crossLinking
	void CellularAutomata::setProperties( CellularAutomata CA[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER] , int type, float age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, int sensingRadius , float fiberDensity, float crossLinking )
	 {
	 	int i;
	 	int j;

	 	for( i=CELLULAR_AUTOMATA_ROW_START; i<= CELLULAR_AUTOMATA_ROW_END; i++ )
	 	 {
	 	 	for ( j=CELLULAR_AUTOMATA_COLUMN_START; j<= CELLULAR_AUTOMATA_COLUMN_END; j++ )
	 	 	 {
	 	 	 	// user / pre  defined values , and parameter list

	 	 	 	if( type == ES )
	 	 	 	 {
	 	 	 	 	// parameter list
	 	 	 	 	// int type, float fiberDensity, float crossLinking
	 	 	 	 	CA[i][j].setESProperties(type, fiberDensity, crossLinking);
	 	 	 	 }
	 	 	 	else	// It is Biological Cell
	 	 	 	 {
	 	 	 	 	// parameter list
	 	 	 	 	// int type, float age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius
	 	 	 	 	CA[i][j].setBiologicalCellProperties(type, age, stiffness, divisionRate, size,	contractility, invasiveness, degradationPotential, sensingRadius);
	 	 	 	 }
	 	 	 }
	 	 }

	 }

 	// int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, int sensingRadius
	void CellularAutomata::setBiologicalCellProperties( int type, float age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, int sensingRadius )
 	 {
 	 	this->type = type;

 	 	this->age = age;
		this->stiffness = stiffness;
		this->divisionRate = divisionRate;
		this->size = size;
		this->contractility = contractility;
		this->invasiveness = invasiveness;
		this->fiberDegradationPotential = degradationPotential;

		this->sensingRadius = sensingRadius;

 	 }

 	// int type, int fiberDensity, float crossLinking
	void CellularAutomata::setESProperties( int type, float fiberDensity, float crossLinking )
 	 {
 	 	this->type = type;

		this->fiberDensity = fiberDensity;
		this->crossLinking = crossLinking;
 	 }

	// reset values of Biological Cell
	void CellularAutomata::resetBiologicalCellProperties()
	 {
	 	type = ES;

 	 	age = 0;
		stiffness = 0;
		divisionRate = 0;
		size = 0;
		contractility = 0;
		invasiveness = 0;
		fiberDegradationPotential = 0;

		sensingRadius = 0;

		// should we reset all values of ECM Site properties
		// atomic

		// will lead to reset of other es properties

	 }

	// reset values of ECM Site
	void CellularAutomata::resetESProperties()
	 {
	 	type = ES;

		fiberDensity = 0;
		crossLinking = 0;

		// should we reset all values of Biological Cell properties
		// atomic

		// will lead to reset of other bc properties
	 }


	// Update Division Rate of Biological Cell
	void CellularAutomata::updateDivisionRate( int totalNumberOfESInNeighbourhood )
	 {
	   this->setDivisionRate( ( 9.0 / 8.0 ) * ( (float) totalNumberOfESInNeighbourhood / ( (float) ( totalNumberOfESInNeighbourhood + 1 ) ) ) );
	 }

	// Update Stiffness of Biological Cell
	void CellularAutomata::updateStiffness( float sumOfCrossLinking, int totalNumberOfESInNeighbourhood )
	 {
	 	float averageCrossLinking;

	 	averageCrossLinking = sumOfCrossLinking / ( (float) totalNumberOfESInNeighbourhood );

	 	this->setStiffness( averageCrossLinking );
	 }

	// Update Degradation Potential of Biological Cell
	void CellularAutomata::updateFiberDegradationPotential( float sumOfFiberDensity )
	 {
	   this->setFiberDegradationPotential( LAMBDA * 1.125 * ( sumOfFiberDensity /  ( sumOfFiberDensity + 1 ) ) );
	 }

	float calculateFiberDegradationPotential( float sumOfFiberDensity )
	 {
	   return ( LAMBDA * ( 85.0 / 80.0 ) * ( sumOfFiberDensity /  ( sumOfFiberDensity + 5 ) ) );
	 }

	// Update Fiber Density of Extra Cellular Matrix Site
	void CellularAutomata::updateFiberDensity( float currentFiberDensity, float updatedFiberDegradationPotential )
	 {

       if( ( currentFiberDensity - updatedFiberDegradationPotential ) > 0 )
        {
          this->setFiberDensity( currentFiberDensity - updatedFiberDegradationPotential );
        }
       else
        {
          this->setFiberDensity( 0 );
        }
	 }

	// Increment age of Biological Cell under consideration by a unit
	void CellularAutomata::incrementAge( )
	 {
 	   this -> setAge( this->getAge() + 1 );
	 }

	// Increment age of Biological Cell under consideration by delta
	void CellularAutomata::incrementAge( float delta )
	 {
 	   this -> setAge( this->getAge() + delta );
	 }

	 void CellularAutomata::moveCell( CellularAutomata *toRandomlySelectedES )
	  {
            // int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius
	       toRandomlySelectedES -> setBiologicalCellProperties( this -> getType(), this->getAge(), this->getStiffness() , this->getDivisionRate(), this->getSize(),
	       this->getContractility(), this->getInvasiveness(), this->getFiberDegradationPotential(), this->getSensingRadius());


	       if ( toRandomlySelectedES -> isTransientAmplifyingCell() )
	        {
   	          toRandomlySelectedES -> setBeta( this -> getBeta() );
	          toRandomlySelectedES -> setRemainingRoundsOfAmplification( this -> getRemainingRoundsOfAmplification() );
	        }

	       // swap identity
	       int identity = toRandomlySelectedES -> getIdentity();

	       toRandomlySelectedES -> setIdentity( this -> getIdentity() );

	       this -> setIdentity( identity );


           // reset or retain properties of ES
	       this -> resetBiologicalCellProperties();
	       this -> resetESProperties();
	  }



	 // Update state / Division of Cancer Stem Cell to Transient Amplifying Cell or Cancer Stem Cell
	 // condition to ALPHA and availability of free neighbour
	 void CellularAutomata::updateStateOfCancerStemCell( CellularAutomata *randomlySelectedES )
	  {
	    // Set Biological Set type to TAC and age to 0

	   	// Divide only if age is greater than Doubling Time

        if ( ( this -> getAge() >= DOUBLINGTIME ) && ( randomlySelectedES -> getFiberDensity() <= STATE_OF_FIBER_DENSITY_FOR_CSC_OR_TAC_TO_REPLICATE ) )
        {
            double alp =  (double)(rand()%10000)/10000.0;		// Generate random number between (0,1)

            if( alp < ALPHA )
              {
                //Symmetric Division into

                // into One CSC
                    this -> resetESProperties();
                    // int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius
                            //                          CSC  Age 0                     0.5
                    this -> setBiologicalCellProperties(CSC, 0, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 1);


                // and CSC
                randomlySelectedES -> resetESProperties();

                // int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius
                                      //                          CSC  Age 0                     0.5
                randomlySelectedES -> setBiologicalCellProperties(CSC, 0, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 1);

              }
            else
             {
                //Asymmetric Division into

                //One CSC
                this -> resetESProperties();
                        // int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius
                        //                          CSC  Age 0                     0.5
                this -> setBiologicalCellProperties(CSC, 0, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 1);



                //One TDC
                randomlySelectedES -> resetESProperties();

                // int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius

                                        //                        TAC  Age 0                     0.5
                randomlySelectedES -> setBiologicalCellProperties(TAC, 0, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 1);

                randomlySelectedES -> setRemainingRoundsOfAmplification(BETA);
             }
        }

	  }


	 // Update state / Division of Transient Amplifying Cell to Terminally Differentiated Cells or Transient Amplifying Cell
	 // condition to cell age , BETA and availability of free neighbour
	 void CellularAutomata::updateStateOfTransientAmplifyingCell( CellularAutomata *randomlySelectedES, bool inRandomFreeNeighbourFound )
	  {
	  			// Is cell a Transient Amplifying Cell

        if ( this -> getAge() >= DOUBLINGTIME )
          {

	  	 	if( this->getRemainingRoundsOfAmplification() >= 1 )	// If Biological Cell type is TAC and Age is greater than BETA
	  	 	 {
			 	// If Biological Cell type is TAC and Age is less than BETA

			 	// Check for free cells in neighbourhood - check if any ECM Site in Neighbourhood

			 	// if free space exists	// Set Biological Set type to TAC and age to 0

			 	 	if( (inRandomFreeNeighbourFound == true) && ( randomlySelectedES -> getFiberDensity() <= STATE_OF_FIBER_DENSITY_FOR_CSC_OR_TAC_TO_REPLICATE ) )
			 	 	 {
						// Beta decrements for daughter cells
						this -> resetESProperties();

						this -> setRemainingRoundsOfAmplification( this -> getRemainingRoundsOfAmplification() - 1 );

					        // int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius
                                    //                          TAC  Age 0                     0.5
					        this -> setBiologicalCellProperties(TAC, 0, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 1);



						randomlySelectedES -> resetESProperties();

						// int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius
                                              //                          TAC  Age 0                     0.5
						randomlySelectedES -> setBiologicalCellProperties(TAC, 0, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 1);

					    randomlySelectedES -> setBeta( this -> getRemainingRoundsOfAmplification() );
			 	 	 }

	  	 	 }
	  	 	else
			 {
	  	 	 	this -> setType(TDC);		    // Set the Biological Cell type to Terminally Differentiated Cell
	  	 	 	this -> setFiberDegradationPotential( 0.5 );
				this -> setAge(0);
			 }
        }
	  }

	 // Update state of Terminally Differentiated Cell to ECM Site, condition to cell age and GAMMA
	 void CellularAutomata::updateStateOfTerminallyDifferentiatedCell( )
	  {
	  				//If Biological Cell type is Terminally Differentiated Cell

	  	 	if( this -> getAge() >= GAMMA )		// And if Age is greater than GAMMA
	  	 	 {
	  	 	 	//Set cell type as ECM Site, fiber density as 0 , cross linking as 0

	  	 		this -> resetBiologicalCellProperties();

	  	 		this -> resetESProperties();

	  	 	 }
	  }

    void inRandomFindESInNeighbourhood( CellularAutomata CA[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER] , int x, int y, double probabilityOfPlacement, int *rx, int *ry, bool * inRandomESInNeighbourFound )
      {
        int m = 0;
        int n = 0;

        int freeESCoOrdinates[8][2];
        int countOfES = 0;
        int i = 0;

        int randomIndex = 0;


        //cout << "\n Checking Neighbour ES for ( x, y ) ( " << x << ", " << y << " )";

        for( m=x-1; m<=x+1; m++ )
        {
            for( n=y-1; n<=y+1; n++ )
            {
               if( !( ( m==x ) && ( n==y ) ) )
                {
                    if( CA[m][n].isES() )
                     {
                       freeESCoOrdinates[i][0] = m;
                       freeESCoOrdinates[i][1] = n;

                       countOfES++;

                       //cout << "\n ES " << countOfES << " ( " << m << ", " << n << " )";

                       i++;
                     }
                }
            }
        }


        if( countOfES != 0 )
         {
            randomIndex = rand() % countOfES; // random number in (0 , countOfES)

                                              // so 1 / countOfES , one out of countOfES will be selected
           *rx = freeESCoOrdinates[randomIndex][0];
           *ry = freeESCoOrdinates[randomIndex][1];

           *inRandomESInNeighbourFound = true;
         }


//        double p_random=0;
//
//        // In Random find a free cell, coordinates, indices in neighbourhood
//        for( m=x-1; m<=x+1; m++ )
//        {
//            for( n=y-1; n<=y+1; n++ )
//            {
//                if( CA[m][n].isES() )
//                 {
//                    p_random = (double)(rand()%10000)/10000.0;
//
//                    if( p_random <= probabilityOfPlacement )
//                    {
//                        *rx = m;             //Save the coordinates, indices
//                        *ry = n;
//
//                        n = y + 2;          // To break out of for loop , instead of using break
//                        m = x + 2;          // Just following Edsger Wybe Dijkstra. All Hail!
//
//                        *inRandomFreeNeighbourFound = true;
//
//                        //cout <<"\n Header - Free Random Space - rx " << *rx << " , ry " << *ry << " , inRandomFreeNeighbourFound " << *inRandomFreeNeighbourFound << " for x, y "<< x<<", "<<y;
//                    }
//                 }
//            }
//        }

      }
