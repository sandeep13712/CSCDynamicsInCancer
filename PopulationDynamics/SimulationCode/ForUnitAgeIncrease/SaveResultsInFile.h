#include <string.h>
#include <sstream>
#include <string> // this should be already included in <sstream>
#include <stdlib.h>

using namespace std;

CellularAutomata tempCA[ROWS+1][COLUMNS+1];
// Write Results into File

	void CellularAutomata::createResultsFile()
	 {
	   ofstream simulationResultFileStream;

	 	std::stringstream fileNameStream;

		fileNameStream << "AlphaPoint" + std::to_string((int) (ALPHA*100) ) + "Beta" + std::to_string(BETA) + "Gamma" + std::to_string(GAMMA) ;

		if( SIGMA == 0 )
		 {
		  fileNameStream << "Sigma0";
		 }
		else
		 {
		   if( SIGMA == 1 )
		    {
		     fileNameStream << "Sigma1";
		    }
		   else
		    {
		     fileNameStream << "SigmaPoint" +  std::to_string((int) (SIGMA*100) ) ;
		    }
		 }

        fileNameStream << "With" + std::to_string((int)FIBERDENSITY) + "FD" ;

		if( MU == 0 )
		 {
		   fileNameStream << "MU0";
		 }
		else
		 {
		   if( MU == 1 )
		    {
		      fileNameStream << "MU1";
		    }
		   else
		    {
		      fileNameStream << "MUPoint" + std::to_string( (int) (MU*100) ) ;
		    }

		 }

		if( LAMBDA == 0 )
		 {
		   fileNameStream << "LAMBDA0";
		 }
		else
		 {
		   if( MU == 1 )
		    {
		      fileNameStream << "LAMBDA1";
		    }
		   else
		    {
		      fileNameStream << "LAMBDAPoint" + std::to_string( (int) (LAMBDA*100) ) ;
		    }
		 }

        fileNameStream << "InSimulationStepsOf" << to_string( SIMULATION_STEPS ) <<".csv";

        std::string fileName = fileNameStream.str();


		simulationResultFileStream.open (fileName);


	   simulationResultFileStream <<"RunRun, CSCInZone1, CSCInZone2, CSCInZone3, CSCInZone4, CSCInZone5, ";

	   simulationResultFileStream <<"TACInZone1, TACInZone2, TACInZone3, TACInZone4, TACInZone5, ";

	   simulationResultFileStream <<"TDCInZone1, TDCInZone2, TDCInZone3, TDCInZone4, TDCInZone5, ";

	   simulationResultFileStream << "TotalFiberDensity, FDInZone1, FDInZone2, FDInZone3, FDInZone4, FDInZone5, ";

	   simulationResultFileStream << "ESInZone1, ESInZone2, ESInZone3, ESInZone4, ESInZone5, ";

	   for( int zone=1; zone<=5; zone++ )
	    {
	      for( int TACWithBeta=0; TACWithBeta<=10; TACWithBeta++ )
	       {
	         simulationResultFileStream << "TACWithBeta" +  std::to_string(TACWithBeta) + "InZone" +  std::to_string(zone) + ", ";
	       }
	    }

	   simulationResultFileStream << endl;

	   simulationResultFileStream.close();

	 }

	// write results of Cellular Automata  into files for cell property
	void CellularAutomata::writeResultsToFile( CellularAutomata CA[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER] , int run )
	 {
	 	long int i;
	 	long int j;
	 	int m;
	 	int n;

	 	long int ESInZone[6]={0};
        //      Zone 1 to 5
	 	// ES

        double totalFiberDensity=0;
	 	double FiberDensityInZone[6]={0};

	 	long int BCInZone[4][6]={0};
	 	//      Zone 1 to 5
	 	// CSC
	 	// TAC
	 	// TDC

	 	long int numberOfTACWithRemainingRoundsOfAmplification[6][11]={0};
	 	//         Zone 1 to 5
	 	// Beta 0
	 	// Beta 1
	 	// Beta 2
	 	// . .
	 	// Beta 10

        PropertiesOfBiologicalCell biologicalCell;
        PropertiesOfExtraCellularMatrixSite eS;

	 	ofstream simulationResultFileStream;
	 	ofstream simulationStepFileStream;

	 	std::stringstream fileNameStream;
	 	std::stringstream simulationStepFileNameStream;

		fileNameStream << "AlphaPoint" + std::to_string((int) (ALPHA*100) ) + "Beta" + std::to_string(BETA) + "Gamma" + std::to_string(GAMMA) ;

		if( SIGMA == 0 )
		 {
		  fileNameStream << "Sigma0";
		 }
		else
		 {
		   if( SIGMA == 1 )
		    {
		     fileNameStream << "Sigma1";
		    }
		   else
		    {
		     fileNameStream << "SigmaPoint" +  std::to_string((int) (SIGMA*100) ) ;
		    }
		 }


        fileNameStream << "With" + std::to_string((int)FIBERDENSITY) + "FD" ;

		if( MU == 0 )
		 {
		   fileNameStream << "MU0";
		 }
		else
		 {
		   if( MU == 1 )
		    {
		      fileNameStream << "MU1";
		    }
		   else
		    {
		      fileNameStream << "MUPoint" + std::to_string( (int) (MU*100) ) ;
		    }

		 }

		if( LAMBDA == 0 )
		 {
		   fileNameStream << "LAMBDA0";
		 }
		else
		 {
		   if( MU == 1 )
		    {
		      fileNameStream << "LAMBDA1";
		    }
		   else
		    {
		      fileNameStream << "LAMBDAPoint" + std::to_string( (int) (LAMBDA*100) ) ;
		    }
		 }

        fileNameStream << "InSimulationStepsOf" << to_string( SIMULATION_STEPS ) <<".csv";

        std::string fileName = fileNameStream.str();

		//strcat ( fileName, std::to_string(ALPHA) );
		//strcat ( fileName, sprintf(bufSecs,"%s",ALPHA) );



		//ALPHA, BETA, GAMMA, STATE_OF_FIBER_DENSITY_FOR_CSC_OR_TAC_TO_REPLICATE,
		//STATE_OF_FIBER_DENSITY_FOR_BIOLOGICAL_CELL_TO_MOVE, FIBERDENSITY, DOUBLINGTIME,
		//SIMULATION_STEPS, MOTILITYPOTENTIAL, FRACTION_OF_ES_WITH_FIBERS, DEGRADATION


		simulationResultFileStream.open (fileName, ios::app);

		//biologicalCell.caluclatePropertiesOfBC(CA);

	 	//eS.caluclatePropertiesOfES(CA);

   	 	for( i=CELLULAR_AUTOMATA_ROW_START, m=1; i<= CELLULAR_AUTOMATA_ROW_END; i++, m++ )
	 	 {
	 	 	for( j=CELLULAR_AUTOMATA_COLUMN_START, n=1; j<= CELLULAR_AUTOMATA_COLUMN_END; j++, n++ )
	 	 	 {
	 	 	   // all other values

	 	 	   tempCA[m][n].setAge( CA[i][j].getAge() );
	 	 	   tempCA[m][n].setBeta( CA[i][j].getBeta() );
	 	 	   tempCA[m][n].setContractility( CA[i][j].getContractility() );
	 	 	   tempCA[m][n].setCrossLinking( CA[i][j].getCrossLinking() );
	 	 	   tempCA[m][n].setDivisionRate( CA[i][j].getDivisionRate() );
	 	 	   tempCA[m][n].setFiberDegradationPotential( CA[i][j].getFiberDegradationPotential() );
	 	 	   tempCA[m][n].setFiberDensity( CA[i][j].getFiberDensity() );
	 	 	   tempCA[m][n].setIdentity( CA[i][j].getIdentity() );
	 	 	   tempCA[m][n].setInvasiveness( CA[i][j].getInvasiveness() );
	 	 	   tempCA[m][n].setRemainingRoundsOfAmplification( CA[i][j].getRemainingRoundsOfAmplification() );
	 	 	   tempCA[m][n].setSensingRadius( CA[i][j].getSensingRadius() );
	 	 	   tempCA[m][n].setSize( CA[i][j].getSize() );
	 	 	   tempCA[m][n].setStiffness( CA[i][j].getStiffness() );
	 	 	   tempCA[m][n].setType( CA[i][j].getType() );

	 	 	 }
	 	 }


 	    if( ( run == 0 ) || ( run == 1 ) || ( ( run % 10 ) == 0 ) )
 	     {
 	     simulationStepFileNameStream << "./Txt/SimulationStep" << to_string( run ) << ".txt";

 	     std::string simulationStepFile = simulationStepFileNameStream.str();

 	     simulationStepFileStream.open( simulationStepFile );

 	       for( i=1; i<= ROWS; i++ )
 	        {
 	          for( j=1; j<= COLUMNS; j++ )
 	            {
 	              if( tempCA[i][j].isES() )
 	               {
 	                 if(  tempCA[i][j].getFiberDensity() == 0 )
 	                  {
 	                    simulationStepFileStream << 0 << " ";
                      }
                     else
                      {
 	                    simulationStepFileStream << 1000 + tempCA[i][j].getFiberDensity() + 1 << " ";
                      }
                    }
 	              else if( tempCA[i][j].isCancerStemCell() )
 	               {
 	                 simulationStepFileStream << 1 << " ";
 	               }
 	              else if( tempCA[i][j].isTransientAmplifyingCell() )
 	               {
 	                 simulationStepFileStream << 10 + tempCA[i][j].getBeta() + 1 << " ";
 	               }
 	              else if( tempCA[i][j].isTerminallyDifferentiatedCell() )
 	               {
 	                 simulationStepFileStream << 100 + tempCA[i][j].getAge() + 1 << " ";
 	               }

 	            }
 	          simulationStepFileStream << endl;
 	        }

         simulationStepFileStream.close();
 	     }

 	    for( i=1; i<= ROWS; i++ )
        {
          for( j=1; j<= COLUMNS; j++ )
          {

            //Zone 5
            if( tempCA[i][j].isES() )
            {
              if(  tempCA[i][j].getFiberDensity() != 0 )
              {
                ESInZone[5]++;
                FiberDensityInZone[5] = FiberDensityInZone[5] + tempCA[i][j].getFiberDensity();
                totalFiberDensity = totalFiberDensity + tempCA[i][j].getFiberDensity();
              }
            }
            else
            {
              BCInZone[ tempCA[i][j].getType() ][5]++;

              if( tempCA[i][j].isTransientAmplifyingCell() )
               {
                 numberOfTACWithRemainingRoundsOfAmplification[ 5 ] [ tempCA[i][j].getRemainingRoundsOfAmplification() ] ++ ;
               }
            }

            if( ( i>= 10 && i<=189 ) && ( j>=10 && j<=189 ) )
            {
                if( tempCA[i][j].isES() )
                {
                  if(  tempCA[i][j].getFiberDensity() != 0 )
                  {
                    ESInZone[4]++;
                    FiberDensityInZone[4] = FiberDensityInZone[4] + tempCA[i][j].getFiberDensity();
                  }
                }
                else
                {
                  BCInZone[ tempCA[i][j].getType() ][4]++;

                  if( tempCA[i][j].isTransientAmplifyingCell() )
                   {
                     numberOfTACWithRemainingRoundsOfAmplification[ 4 ][ tempCA[i][j].getRemainingRoundsOfAmplification() ] ++ ;
                   }
                }
            }


            if( ( i>= 22 && i<=177 ) && ( j>=22 && j<=177 ) )
            {
                if( tempCA[i][j].isES() )
                {
                  if(  tempCA[i][j].getFiberDensity() != 0 )
                  {
                    ESInZone[3]++;
                    FiberDensityInZone[3] = FiberDensityInZone[3] + tempCA[i][j].getFiberDensity();
                  }
                }
                else
                {
                  BCInZone[ tempCA[i][j].getType() ][3]++;

                  if( tempCA[i][j].isTransientAmplifyingCell() )
                   {
                     numberOfTACWithRemainingRoundsOfAmplification[ 3 ][ tempCA[i][j].getRemainingRoundsOfAmplification() ] ++ ;
                   }
                }
            }


            if( ( i>= 37 && i<=163 ) && ( j>=37 && j<=163 ) )
            {
                if( tempCA[i][j].isES() )
                {
                  if(  tempCA[i][j].getFiberDensity() != 0 )
                  {
                    ESInZone[2]++;
                    FiberDensityInZone[2] = FiberDensityInZone[2] + tempCA[i][j].getFiberDensity();
                  }
                }
                else
                {
                  BCInZone[ tempCA[i][j].getType() ][2]++;

                  if( tempCA[i][j].isTransientAmplifyingCell() )
                   {
                     numberOfTACWithRemainingRoundsOfAmplification[ 2 ][ tempCA[i][j].getRemainingRoundsOfAmplification() ] ++ ;
                   }
                }
            }


            if( ( i>= 55 && i<=144 ) && ( j>=55 && j<=144 ) )
            {
                if( tempCA[i][j].isES() )
                {
                  if(  tempCA[i][j].getFiberDensity() != 0 )
                  {
                    ESInZone[1]++;
                    FiberDensityInZone[1] = FiberDensityInZone[1] + tempCA[i][j].getFiberDensity();
                  }
                }
                else
                {
                  BCInZone[ tempCA[i][j].getType() ][1]++;

                  if( tempCA[i][j].isTransientAmplifyingCell() )
                   {
                     numberOfTACWithRemainingRoundsOfAmplification[ 1 ][ tempCA[i][j].getRemainingRoundsOfAmplification() ] ++ ;
                   }
                }
            }

          }
        }



	 	//      Zone 1 to 5
	 	// ES
	 	// CSC
	 	// TAC
	 	// TDC

	 	//         Zone 1 to 5
	 	// Beta 0
	 	// Beta 1
	 	// Beta 2
	 	// . .
	 	// Beta 10

        for( i=1; i<=3; i++ )
         {
           for( j=5; j>=2; j-- )
            {
              BCInZone[i][j] = BCInZone[i][j] - BCInZone[i][j-1];
            }
         }

        for( i=5; i>=2; i-- )
         {
              ESInZone[i] = ESInZone[i] - ESInZone[i-1];
         }

        for( i=5; i>=2; i-- )
         {
           FiberDensityInZone[i] = FiberDensityInZone[i] - FiberDensityInZone[i-1];
         }

        for( i=5; i>=2; i--)
         {
           for( j=0; j<=10; j++ )
            {
              numberOfTACWithRemainingRoundsOfAmplification[i][j] =
              numberOfTACWithRemainingRoundsOfAmplification[i][j] - numberOfTACWithRemainingRoundsOfAmplification[i-1][j];
            }
         }

	 	 simulationResultFileStream << run << ", ";

	 	 for( i=1; i<=3; i++ )
         {
           for( j=1; j<=5; j++ )
            {
              simulationResultFileStream << BCInZone[i][j] <<", ";
            }
         }

         simulationResultFileStream << totalFiberDensity << ", ";

         for( i=1; i<=5; i++ )
         {
           simulationResultFileStream << FiberDensityInZone[i] << ", ";
         }

         for( i=1; i<=5; i++ )
         {
           simulationResultFileStream << ESInZone[i] << ", ";
         }

         for( i=1; i<=5; i++ )
          {
            for( j = 0; j<=10; j++ )
             {
               simulationResultFileStream <<  numberOfTACWithRemainingRoundsOfAmplification[i][j] << ", ";
             }
          }


	 	 simulationResultFileStream << endl;

	 	 simulationResultFileStream.close();

	 }

