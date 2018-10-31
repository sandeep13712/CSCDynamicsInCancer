// Update function
// Run ITERATIONS times
// And In each ITERATIONS ,  ROWS * COLUMNS times one random cell is selected to update

void update( CellularAutomata CA[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER] )
 {
    cout << "\n In Update Function - ";

    long int i;              // Iterator
    int m;              // Iterators for indices of free cells in neighbourhood
 	int n;

 	int x = 0;              // Variable to hold co ordinates ( x, y )
 	int rx = 0;
 	int y = 0;
 	int ry = 0;

 	bool inRandomESInNeighbourFound = false;

 	int randomNumber = 0;   // to hold Random number used to select update function of ES

 	long int run = 0;		//Counts from 0 to number of iterations

 	PropertiesOfBiologicalCell biologicalCellInNeighbourhood;
 	PropertiesOfExtraCellularMatrixSite eSInNeighbourhood;

    double p_random;                       // hold random number to check with ALPHA for CSC cells
    double probabilityOfPlacement;          // hold 1 / number of specific cell in neighbourhood
    double probabilityOfMovementOrDivision;

    float previousFiberDensity;

    float newFiberDensity;

    float differenceInFiberDensity;

    float fiberDegradationPotential;

    float fiberDensity;

    float delta;


    cout <<"\n Writing constants to file - ";

   	//CA[0][0].writeConstantsIdentityAndIterationsIntoFile(CA);     //Write Constants , Iterators into file

   	CA[0][0].createResultsFile();

   	CA[0][0].writeResultsToFile(CA, run);


    CA[0][0].setNumberOfFibersDegradedByBC(0);
 	CA[0][0].setNumberOfFibersReplacedByBC(0);

    CA[0][0].setNumberOfFibersDegradedByCSC(0);
    CA[0][0].setNumberOfFibersReplacedByCSC(0);

    CA[0][0].setNumberOfFibersDegradedByTAC(0);
    CA[0][0].setNumberOfFibersReplacedByTAC(0);

    CA[0][0].setNumberOfFibersDegradedByTDC(0);
    CA[0][0].setNumberOfFibersReplacedByTDC(0);

    cout <<"\n Startign Iterations ";

   	while( run != SIMULATION_STEPS )
 	 {

 	 	cout <<"\n Simulation - "<< ++run;


 	 	CA[0][0].setNumberOfFibersDegradedByBC(0);
 	 	CA[0][0].setNumberOfFibersReplacedByBC(0);

 	 	CA[0][0].setNumberOfFibersReplacedByCSC(0);
 	 	CA[0][0].setNumberOfFibersDegradedByCSC(0);

 	 	CA[0][0].setNumberOfFibersReplacedByTAC(0);
 	 	CA[0][0].setNumberOfFibersDegradedByTAC(0);

 	 	CA[0][0].setNumberOfFibersDegradedByTDC(0);
 	 	CA[0][0].setNumberOfFibersReplacedByTDC(0);

	 	// finding neighbours straight forward for inner cells as compared to finding neighbours for the boundary cell

	 	// for boundary cell - neighbours be toroid using modulus to find neighbours if cell in first row, column or last row, column

	 	// Assuming the padding case of cellular automata

	 	// initial check cell m = -1 or -2 . .  depends on sensing radius

	 	// assuming of sensing radius = 1

	 	for( i=1; i<= ROWS*COLUMNS ; i++ )
	 	 {
			x = 0;
			y = 0;
			rx = 0;
			ry = 0;

			inRandomESInNeighbourFound = false;

			//if( i%50 == 0 )
			// {
			//   cout <<"\n Sub iteration - " << i;
			// }


			x = ( rand() % ROWS ) + CELLULAR_AUTOMATA_ROW_START;                        //Select one cell in Random
	 	 	y = ( rand() % COLUMNS ) + CELLULAR_AUTOMATA_COLUMN_START;

			if ( CA[x][y].isES() )		                // Is it ECM Site
			 {
                // ES is not an active entity
                // So we are not updating the fiber density
                //   As it will be done by Biological Cell when they are surrounded by ES and only when cell have no free location to move or divide.
			 }

			else					                    // then it is Biological Cell
			 {

			 // Increment Age of the Cell

			   if( CA[x][y].isCancerStemCell() || CA[x][y].isTransientAmplifyingCell() )
			    {
			      eSInNeighbourhood.caluclatePropertiesOfESInNeighbourhood( CA , x , y );

			      fiberDensity = eSInNeighbourhood.getSumOfFiberDensityInNeighbourhood();

			      delta = 1 +  1.125*(fiberDensity)/(fiberDensity+1);

			      //cout <<"\n delta "<< delta;

			      CA[x][y].incrementAge( delta );
                }
               else
                {
                  CA[x][y].incrementAge( 1 );
                }


             // Check for free space
             // If free either move or divide
             // else degrade fiber

             rx = 0;
             ry = 0;

             inRandomESInNeighbourFound = false;
             eSInNeighbourhood.caluclatePropertiesOfESInNeighbourhood( CA, x, y);

             if( eSInNeighbourhood.getTotalNumberOfESInNeighbourhood() != 0 )
               {
                 probabilityOfPlacement = 1/(double)(eSInNeighbourhood.getTotalNumberOfESInNeighbourhood());

                 inRandomFindESInNeighbourhood( CA, x, y, probabilityOfPlacement, &rx, &ry, &inRandomESInNeighbourFound );
               }

             if ( inRandomESInNeighbourFound == true )
               {

//                 cout << "\n inRandomESInNeighbourFound";
//                 if(inRandomESInNeighbourFound)
//                   cout << " true";
//                 else
//                   cout <<" false";


                 if( ( CA[rx][ry].getFiberDensity() <= STATE_OF_FIBER_DENSITY_FOR_CSC_OR_TAC_TO_REPLICATE ) || ( CA[rx][ry].getFiberDensity() <= STATE_OF_FIBER_DENSITY_FOR_BIOLOGICAL_CELL_TO_MOVE ) )
                   {
                     // Check Age and Divide
                     // Other wise , move with probability MU

                     // Only CSC and TAC Divide
                     // Check Cell type and Doubling time , if not CSC or TAC then move the cell with Probability MU

                     if( ( CA[x][y].isCancerStemCell() || CA[x][y].isTransientAmplifyingCell() ) && ( CA[x][y].getAge() >= DOUBLINGTIME ) )
                      {

                         // Divide

//                             cout << "\n Divide";

                             if( CA[x][y].isCancerStemCell() )						                                    // then it is a Cancer Stem Cell
                              {
                                   previousFiberDensity = CA[rx][ry].getFiberDensity() ;

                                   CA[x][y].updateStateOfCancerStemCell( &CA[rx][ry] );

                                   newFiberDensity = CA[rx][ry].getFiberDensity() ;

                                    if( ( previousFiberDensity - newFiberDensity ) != 0 )
                                     {
                                       CA[0][0].setNumberOfFibersReplacedByCSC( CA[0][0].getNumberOfFibersReplacedByCSC() + ( previousFiberDensity - newFiberDensity ) );
                                     }
                              }
                             else if ( CA[x][y].isTransientAmplifyingCell() )		                // If it is a Transient Amplifying Cell
                              {
                                previousFiberDensity = CA[rx][ry].getFiberDensity() ;

                                CA[x][y].updateStateOfTransientAmplifyingCell( &CA[rx][ry] , inRandomESInNeighbourFound );

                                newFiberDensity = CA[rx][ry].getFiberDensity() ;

                                if( ( previousFiberDensity - newFiberDensity ) != 0 )
                                 {
                                   CA[0][0].setNumberOfFibersReplacedByTAC( CA[0][0].getNumberOfFibersReplacedByTAC() + ( previousFiberDensity - newFiberDensity ) );
                                 }
                              }
                             else // It is Terminally Differentiated Cell
                              {
                                CA[x][y].updateStateOfTerminallyDifferentiatedCell();
                              }

                      }
                     else
                      {
                          double movementProbability = (double)(rand() % 10000)/10000.0;

                          if( movementProbability < MU )
                            {
                              //cout <<"\n Update - Free Random Space - rx " << rx << " , ry " << ry << " , inRandomFreeNeighbourFound " << inRandomFreeNeighbourFound << " for x, y "<< x<<", "<<y;

                              if ( inRandomESInNeighbourFound == true )
                               {
                                fiberDensity = CA[rx][ry].getFiberDensity();

                                if( CA[rx][ry].getFiberDensity() <= STATE_OF_FIBER_DENSITY_FOR_BIOLOGICAL_CELL_TO_MOVE )
                                 {
                                   if( CA[x][y].isCancerStemCell() )
                                     {
                                       CA[0][0].setNumberOfFibersReplacedByCSC( CA[0][0].getNumberOfFibersReplacedByCSC() + fiberDensity );
                                     }
                                   else if( CA[x][y].isTransientAmplifyingCell() )
                                     {
                                       CA[0][0].setNumberOfFibersReplacedByTAC( CA[0][0].getNumberOfFibersReplacedByTAC() + fiberDensity );
                                     }
                                   else
                                     {
                                       CA[0][0].setNumberOfFibersReplacedByTDC( CA[0][0].getNumberOfFibersReplacedByTDC() + fiberDensity );
                                     }


                                   CA[x][y].moveCell( &CA[rx][ry] );

                                   // reset cordiantes of cell
                                   x = rx;
                                   y = ry;
                                 }
                               }
                            }
                      }

                   }
                 else
                   {
                     // degrade

//                     cout << "\n Degrade";

                            // Update only if there are Biological Cells in Neighbourhood
                            // As the properties of ES depaend on properties of BC in Neighbourhood

                            // We are in this block because of Biological Cell at ( x, y ) found a ES at ( rx, ry ) , but did not qualify for site to divide or move
                            // So now being degraded.


                           eSInNeighbourhood.caluclatePropertiesOfESInNeighbourhood( CA, x, y );

                           //cout << "\n previous Fiber Degradation Potential of ( x, y ) ( " << x << ", " << y << ")" << CA[x][y].getFiberDegradationPotential();

                           CA[x][y].updateFiberDegradationPotential( eSInNeighbourhood.getSumOfFiberDensityInNeighbourhood() );

                           //cout << "\n new Fiber Degradation Potential of ( x, y ) ( " << x << ", " << y << ")" << CA[x][y].getFiberDegradationPotential();



                           //cout << "\n\n Recalculation biologicalCellInNeighbourhood.caluclatePropertiesOfBCInNeighbourhood( CA, rx, ry )";

                           //cout << "\n previous Fiber Degradation Potential of ( x, y ) ( " << x << ", " << y << ")" << CA[x][y].getFiberDegradationPotential();

                           //cout << "\n new Fiber Degradation Potential of ( x, y ) ( " << x << ", " << y << ")" << CA[x][y].getFiberDegradationPotential();


                           previousFiberDensity = CA[rx][ry].getFiberDensity();

                           //cout << "\n previous Fiber Density of ( rx, ry )" << rx << ", " << ry << ") " << CA[rx][ry].getFiberDensity() ;
                           //cout << "\n biologicalCellInNeighbourhood.getAverageOfFiberDegradationPotentialOfBCInNeighbourhood() " << biologicalCellInNeighbourhood.getAverageOfFiberDegradationPotentialOfBCInNeighbourhood() ;
                           //cout << "\n With rounding " << (int) ( CA[rx][ry].getFiberDensity() * ( 1 - biologicalCellInNeighbourhood.getAverageOfFiberDegradationPotentialOfBCInNeighbourhood() ) );
                           //cout << "\n Without Rounding " << (double) ( CA[rx][ry].getFiberDensity() * ( 1 - biologicalCellInNeighbourhood.getAverageOfFiberDegradationPotentialOfBCInNeighbourhood() ) );

                            CA[rx][ry].updateFiberDensity( CA[rx][ry].getFiberDensity(), CA[x][y].getFiberDegradationPotential() );

                            //cout << "\n new Fiber Density of ( rx, ry )" << rx << ", " << ry << ") " << CA[rx][ry].getFiberDensity() ;
                            //cout << "\n biologicalCellInNeighbourhood.getAverageOfFiberDegradationPotentialOfBCInNeighbourhood() " << biologicalCellInNeighbourhood.getAverageOfFiberDegradationPotentialOfBCInNeighbourhood() ;
                            //cout << "\n With rounding " << (int) ( CA[rx][ry].getFiberDensity() * ( 1 - biologicalCellInNeighbourhood.getAverageOfFiberDegradationPotentialOfBCInNeighbourhood() ) );
                            //cout << "\n Without Rounding " << (double) ( CA[rx][ry].getFiberDensity() * ( 1 - biologicalCellInNeighbourhood.getAverageOfFiberDegradationPotentialOfBCInNeighbourhood() ) );

                            newFiberDensity = CA[rx][ry].getFiberDensity();


                            differenceInFiberDensity = previousFiberDensity - newFiberDensity;

                            if( differenceInFiberDensity != 0 )
                             {

                               CA[0][0].setNumberOfFibersDegradedByBC( CA[0][0].getNumberOfFibersDegradedByBC() + differenceInFiberDensity );

                               // Individual Contributions to fiber degradations by CSC , TAC and TDC


                               if( biologicalCellInNeighbourhood.getSumOfFiberDegradationPotentialOfBCInNeighbourhood() != 0 )
                                {
                                  CA[0][0].setNumberOfFibersDegradedByCSC( CA[0][0].getNumberOfFibersDegradedByCSC() +  ( differenceInFiberDensity * (biologicalCellInNeighbourhood.getSumOfFiberDegradationPotentialOfCSCInNeighbourhood()/biologicalCellInNeighbourhood.getSumOfFiberDegradationPotentialOfBCInNeighbourhood() ) ) );

                                  CA[0][0].setNumberOfFibersDegradedByTAC( CA[0][0].getNumberOfFibersDegradedByTAC() +  ( differenceInFiberDensity * (biologicalCellInNeighbourhood.getSumOfFiberDegradationPotentialOfTACInNeighbourhood()/biologicalCellInNeighbourhood.getSumOfFiberDegradationPotentialOfBCInNeighbourhood() ) ) );

                                  CA[0][0].setNumberOfFibersDegradedByTDC( CA[0][0].getNumberOfFibersDegradedByTDC() +  ( differenceInFiberDensity * (biologicalCellInNeighbourhood.getSumOfFiberDegradationPotentialOfTDCInNeighbourhood()/biologicalCellInNeighbourhood.getSumOfFiberDegradationPotentialOfBCInNeighbourhood() ) ) );
                                }

                             }

                   }
               }
             else
               {
                 // There are no ES in Neighbourhood
                 // Properties of TDC and for TAC to transit to TDC - are not dependant on neighbour ES
                 // So check and update its state

                 if ( CA[x][y].isTransientAmplifyingCell() )		                // If it is a Transient Amplifying Cell
                  {
                    previousFiberDensity = CA[rx][ry].getFiberDensity() ;

                    CA[x][y].updateStateOfTransientAmplifyingCell( &CA[rx][ry] , inRandomESInNeighbourFound );

                    newFiberDensity = CA[rx][ry].getFiberDensity() ;

                    if( ( previousFiberDensity - newFiberDensity ) != 0 )
                     {
                       CA[0][0].setNumberOfFibersReplacedByTAC( CA[0][0].getNumberOfFibersReplacedByTAC() + ( previousFiberDensity - newFiberDensity ) );
                     }
                  }

                 else if( CA[x][y].isTerminallyDifferentiatedCell() )
                  {
                    CA[x][y].updateStateOfTerminallyDifferentiatedCell();
                  }
               }


			 }

	 	 }
		// now call write into file , instead of only once after iterations
		// open file in apend mode

		CA[0][0].writeResultsToFile(CA, run);

		//CA[0][0].writeResultsToFile(CA);
 	 }

 }
