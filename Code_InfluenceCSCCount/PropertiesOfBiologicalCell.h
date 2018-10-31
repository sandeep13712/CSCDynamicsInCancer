// Class for properties of Properties Of Biological Cell In Neighbourhood
// like totalNumberOfBCInNeighbourhood , sumOfDegradationPotentialOfBCInNeighbourhood

#include<math.h>

using namespace std;

class PropertiesOfBiologicalCell
 {
   private:

   int totalNumberOfBCInNeighbourhood;                      // Number Of Biological Cells In Neighbourhood

   int totalNumberOfCSCInNeighbourhood;                      // Number Of CSC Cells In Neighbourhood
   int totalNumberOfTACInNeighbourhood;                      // Number Of TAC Cells In Neighbourhood
   int totalNumberOfTDCInNeighbourhood;                      // Number Of TDC Cells In Neighbourhood

   long int totalNumberOfTACWithRemainingRoundsOfAmplification[11];                      // Number Of TAC Cells of , in array each with same remaining rounds of amplification

   float sumOfFiberDegradationPotentialOfBCInNeighbourhood;      // Sum Of Degradation Potential Of Biological Cells In Neighbourhood
   float averageOfFiberDegradationPotentialOfBCInNeighbourhood;      // Average Of Degradation Potential Of Biological Cells In Neighbourhood

   float sumOfFiberDegradationPotentialOfCSCInNeighbourhood;      // Sum Of Degradation Potential Of CSCs In Neighbourhood
   float averageOfFiberDegradationPotentialOfCSCInNeighbourhood;      // Average Of Degradation Potential Of CSCs In Neighbourhood

   float sumOfFiberDegradationPotentialOfTACInNeighbourhood;      // Sum Of Degradation Potential Of TACs In Neighbourhood
   float averageOfFiberDegradationPotentialOfTACInNeighbourhood;      // Average Of Degradation Potential Of TACs In Neighbourhood

   float sumOfFiberDegradationPotentialOfTDCInNeighbourhood;      // Sum Of Degradation Potential Of TDCs In Neighbourhood
   float averageOfFiberDegradationPotentialOfTDCInNeighbourhood;      // Average Of Degradation Potential Of TDCs In Neighbourhood


   long int totalNumberOfBC;                                     // Number Of Biological Cells
   long int totalNumberOfCSC;                                    // Number Of Cancer Stem Cells
   long int totalNumberOfTAC;                                    // Number Of Transient Amplifying Cells
   long int totalNumberOfTDC;                                    // Number Of Terminally Differentiated Cells
   double sumOfFiberDegradationPotentialOfTDC;                     // Sum Of Degradation Potential Of Biological Cells In Neighbourhood
   double averageOfFiberDegradationPotentialOfTDC;                 // Average Of Degradation Potential Of Biological Cells In Neighbourhood
   double standardDeviationOfFiberDegradationPotentialOfTDC;       // Standard Deviation Of Degradation Potential Of Biological Cells In Neighbourhood


   public:

   // Get and Set Functions

   int getTotalNumberOfBCInNeighbourhood();

   void setTotalNumberOfBCInNeighbourhood( int );


   int getTotalNumberOfCSCInNeighbourhood();

   void setTotalNumberOfCSCInNeighbourhood( int );


   int getTotalNumberOfTACInNeighbourhood();

   void setTotalNumberOfTACInNeighbourhood( int );


   int getTotalNumberOfTDCInNeighbourhood();

   void setTotalNumberOfTDCInNeighbourhood( int );


   long int getTotalNumberOfTACWithRemainingRoundsOfAmplification(int);

   long int setTotalNumberOfTACWithRemainingRoundsOfAmplification(int, long int);



   float getSumOfFiberDegradationPotentialOfBCInNeighbourhood();

   void setSumOfFiberDegradationPotentialOfBCInNeighbourhood( float );

   float getAverageOfFiberDegradationPotentialOfBCInNeighbourhood();

   void setAverageOfFiberDegradationPotentialOfBCInNeighbourhood(float);


   float getSumOfFiberDegradationPotentialOfCSCInNeighbourhood();

   void setSumOfFiberDegradationPotentialOfCSCInNeighbourhood( float );

   float getAverageOfFiberDegradationPotentialOfCSCInNeighbourhood();

   void setAverageOfFiberDegradationPotentialOfCSCInNeighbourhood( float );


   float getSumOfFiberDegradationPotentialOfTACInNeighbourhood();

   void setSumOfFiberDegradationPotentialOfTACInNeighbourhood( float );

   float getAverageOfFiberDegradationPotentialOfTACInNeighbourhood();

   void setAverageOfFiberDegradationPotentialOfTACInNeighbourhood( float );


   float getSumOfFiberDegradationPotentialOfTDCInNeighbourhood( );

   void setSumOfFiberDegradationPotentialOfTDCInNeighbourhood( float );

   float getAverageOfFiberDegradationPotentialOfTDCInNeighbourhood( );

   void setAverageOfFiberDegradationPotentialOfTDCInNeighbourhood( float );

   long int getTotalNumberOfBC();

   void setTotalNumberOfBC( long int );

   long int getTotalNumberOfCSC();

   void setTotalNumberOfCSC( long int );

   long int getTotalNumberOfTAC();

   void setTotalNumberOfTAC( long int );

   long int getTotalNumberOfTDC();

   void setTotalNumberOfTDC( long int );

   double getSumOfFiberDegradationPotentialOfTDC();

   void setSumOfFiberDegradationPotentialOfTDC( double );

   void setAverageOfFiberDegradationPotentialOfTDC( double );

   double getAverageOfFiberDegradationPotentialOfTDC();

   void setStandardDeviationOfFiberDegradationPotentialOfTDC(double);

   double getStandardDeviationOfFiberDegradationPotentialOfTDC();

   // Find the property values of Biological Cells In Neighbourhood of ( i, j )th Cell

   // parameters CellularAutomata CA[][12], int i, int j
   void caluclatePropertiesOfBCInNeighbourhood( CellularAutomata[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER], int , int );

   //void caluclatePropertiesOfTDCInNeighbourhood( CellularAutomata[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER], int , int );

   void caluclatePropertiesOfBC( CellularAutomata[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER] );

 };

 void PropertiesOfBiologicalCell::caluclatePropertiesOfBCInNeighbourhood( CellularAutomata CA[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER], int i, int j )
	 {

        int totalNumberOfBCInNeighbourhood = 0;
        int totalNumberOfCSCInNeighbourhood = 0;
        int totalNumberOfTACInNeighbourhood = 0;
        int totalNumberOfTDCInNeighbourhood = 0;

	 	float sumOfFiberDegradationPotentialOfBCInNeighbourhood = 0;

	 	float sumOfFiberDegradationPotentialOfCSCInNeighbourhood = 0;

	 	float sumOfFiberDegradationPotentialOfTACInNeighbourhood = 0;

	 	float sumOfFiberDegradationPotentialOfTDCInNeighbourhood = 0;


	 	this -> setTotalNumberOfBCInNeighbourhood( 0 );
	 	this -> setSumOfFiberDegradationPotentialOfBCInNeighbourhood( 0.0 );
	 	this -> setAverageOfFiberDegradationPotentialOfBCInNeighbourhood( 0.0 );

	 	this -> setTotalNumberOfCSCInNeighbourhood( 0 );
	 	this -> setSumOfFiberDegradationPotentialOfCSCInNeighbourhood( 0.0 );
	 	this -> setAverageOfFiberDegradationPotentialOfCSCInNeighbourhood( 0.0 );

	 	this -> setTotalNumberOfTACInNeighbourhood( 0 );
	 	this -> setSumOfFiberDegradationPotentialOfTACInNeighbourhood( 0.0 );
	 	this -> setAverageOfFiberDegradationPotentialOfTACInNeighbourhood( 0.0 );

	 	this -> setTotalNumberOfTDCInNeighbourhood( 0 );
	 	this -> setSumOfFiberDegradationPotentialOfTDCInNeighbourhood( 0.0 );
	 	this -> setAverageOfFiberDegradationPotentialOfTDCInNeighbourhood( 0.0 );

	 	int m;
	 	int n;

	 	// For 8 Adjacent cells
	 	for( m=-1; m<2; m++ )
	 	 {
	 	 	for( n=-1; n<2; n++ )
	 	 	 {
			   	// If its a Biologicla Site inclrease count
	 	 	 	if( !( m==0 && n==0 ) && CA[i+m][j+n].isBiologicalCell() )
	 	 	 	 {
	 	 	 	 	totalNumberOfBCInNeighbourhood ++;

	 	 	 	 	sumOfFiberDegradationPotentialOfBCInNeighbourhood += CA[i+m][j+n].getFiberDegradationPotential();

	 	 	 	 	if( CA[i+m][j+n].isCancerStemCell() )
	 	 	 	 	 {
	 	 	 	 	   totalNumberOfCSCInNeighbourhood ++;
	 	 	 	 	   sumOfFiberDegradationPotentialOfCSCInNeighbourhood  += CA[i+m][j+n].getFiberDegradationPotential();
	 	 	 	 	 }
	 	 	 	 	else if( CA[i+m][j+n].isTransientAmplifyingCell() )
	 	 	 	 	 {
	 	 	 	 	   totalNumberOfTACInNeighbourhood ++;
	 	 	 	 	   sumOfFiberDegradationPotentialOfTACInNeighbourhood += CA[i+m][j+n].getFiberDegradationPotential();
	 	 	 	 	 }
	 	 	 	 	else
	 	 	 	 	 {
	 	 	 	 	   totalNumberOfTDCInNeighbourhood ++;
	 	 	 	 	   sumOfFiberDegradationPotentialOfTDCInNeighbourhood += CA[i+m][j+n].getFiberDegradationPotential();
	 	 	 	 	 }
	 	 	 	 }
	 	 	 }
	 	 }

	 	 this->setTotalNumberOfBCInNeighbourhood( totalNumberOfBCInNeighbourhood );

	 	 this->setTotalNumberOfCSCInNeighbourhood( totalNumberOfCSCInNeighbourhood );

	 	 this->setTotalNumberOfTACInNeighbourhood( totalNumberOfTACInNeighbourhood );

	 	 this->setTotalNumberOfTDCInNeighbourhood( totalNumberOfTDCInNeighbourhood );


	 	 this -> setSumOfFiberDegradationPotentialOfBCInNeighbourhood( sumOfFiberDegradationPotentialOfBCInNeighbourhood );

	 	 this -> setSumOfFiberDegradationPotentialOfCSCInNeighbourhood( sumOfFiberDegradationPotentialOfCSCInNeighbourhood );

	 	 this -> setSumOfFiberDegradationPotentialOfTACInNeighbourhood( sumOfFiberDegradationPotentialOfTACInNeighbourhood );

	 	 this -> setSumOfFiberDegradationPotentialOfTDCInNeighbourhood( sumOfFiberDegradationPotentialOfTDCInNeighbourhood );


	 	 if( this-> getTotalNumberOfBCInNeighbourhood() != 0 )                       // If any Biological Cell exist in Neighbourhood
	 	  {                                                                          // set the properties
             this -> setAverageOfFiberDegradationPotentialOfBCInNeighbourhood( this -> getSumOfFiberDegradationPotentialOfBCInNeighbourhood() / (float) this -> getTotalNumberOfBCInNeighbourhood() );
	 	  }

	 	 if( this->getTotalNumberOfCSCInNeighbourhood() != 0 )
	 	  {
             this -> setAverageOfFiberDegradationPotentialOfCSCInNeighbourhood( this -> getSumOfFiberDegradationPotentialOfCSCInNeighbourhood() / (float) this -> getTotalNumberOfCSCInNeighbourhood() );
	 	  }

	 	 if( this->getTotalNumberOfTACInNeighbourhood() != 0 )
	 	  {
             this -> setAverageOfFiberDegradationPotentialOfTACInNeighbourhood( this -> getSumOfFiberDegradationPotentialOfTACInNeighbourhood() / (float) this -> getTotalNumberOfTACInNeighbourhood() );
	 	  }

	 	 if( this->getTotalNumberOfTDCInNeighbourhood() != 0 )
	 	  {
             this -> setAverageOfFiberDegradationPotentialOfTDCInNeighbourhood( this -> getSumOfFiberDegradationPotentialOfTDCInNeighbourhood() / (float) this -> getTotalNumberOfTDCInNeighbourhood() );
	 	  }
	 }

/*
 void PropertiesOfBiologicalCell::caluclatePropertiesOfTDCInNeighbourhood( CellularAutomata CA[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER], int i, int j )
	 {
	 	//int totalNumberOfBCInNeighbourhood = 0;

	 	int totalNumberOfTDCInNeighbourhood = 0;

	 	float sumOfFiberDegradationPotentialInNeighbourhood = 0;

	 	this -> setTotalNumberOfTDCInNeighbourhood( 0 );
	 	this -> setSumOfFiberDegradationPotentialOfTDCInNeighbourhood( 0.0 );
	 	this -> setAverageOfFiberDegradationPotentialOfTDCInNeighbourhood( 0.0 );

	 	int m;
	 	int n;

	 	// For 8 Adjacent cells
	 	for( m=-1; m<2; m++ )
	 	 {
	 	 	for( n=-1; n<2; n++ )
	 	 	 {
			   	// If its a Biologicla Site inclrease count
	 	 	 	if( !( m==0 && n==0 ) && CA[i+m][j+n].isTerminallyDifferentiatedCell() )
	 	 	 	 {
	 	 	 	 	totalNumberOfTDCInNeighbourhood ++;
	 	 	 	 }
	 	 	 }
	 	 }

	 	 this->setTotalNumberOfTDCInNeighbourhood( totalNumberOfTDCInNeighbourhood );

	 	 if( this->getTotalNumberOfTDCInNeighbourhood() != 0 )                       // If any Biological Cell exist in Neighbourhood
	 	  {                                                                         // Find the properties
            for( m=-1; m<2; m++ )
             {
                for( n=-1; n<2; n++ )
                 {
                    // If its a Biological Cell Site then sum up Degradation Potential
                    if( !( m==0 && n==0 ) && CA[i+m][j+n].isTerminallyDifferentiatedCell() )
                     {
                        sumOfFiberDegradationPotentialInNeighbourhood =  sumOfFiberDegradationPotentialInNeighbourhood + CA[i+m][j+n].getFiberDegradationPotential();
                     }
                 }
             }

             this -> setSumOfFiberDegradationPotentialOfTDCInNeighbourhood( sumOfFiberDegradationPotentialInNeighbourhood );

             this -> setAverageOfFiberDegradationPotentialOfTDCInNeighbourhood( this -> getSumOfFiberDegradationPotentialOfTDCInNeighbourhood() / (float) this -> getTotalNumberOfTDCInNeighbourhood() );

	 	  }
	 }
*/
void PropertiesOfBiologicalCell::caluclatePropertiesOfBC( CellularAutomata CA[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER] )
	 {
	 	int m;
	 	int n;

        long int totalNumberOfBC = 0;
        long int totalNumberOfCSC = 0;
        long int totalNumberOfTAC = 0;
        long int totalNumberOfTDC = 0;
        double sumOfDegradationPotentialOfBC = 0;
        double sDOfDegradationPotentialOfBC = 0;

        long int numberOfTACWithSpecificRemainingRoundsOfAmplification[11]={0};

        double sumOfDegradationPotentialOfCSC = 0;
        double sDOfDegradationPotentialOfCSC = 0;

        double sumOfDegradationPotentialOfTAC = 0;
        double sDOfDegradationPotentialOfTAC = 0;

        double sumOfDegradationPotentialOfTDC = 0;
        double sDOfDegradationPotentialOfTDC = 0;

	 	this -> setTotalNumberOfBC(0) ;
	 	this -> setTotalNumberOfCSC(0);
	 	this -> setTotalNumberOfTAC(0);
	 	this -> setTotalNumberOfTDC(0);
	 	this -> setSumOfFiberDegradationPotentialOfTDC( 0.0 );
        this -> setAverageOfFiberDegradationPotentialOfTDC( 0.0 );
        this -> setStandardDeviationOfFiberDegradationPotentialOfTDC( 0.0 );

        // For Entire Cellular Automata
	 	for( m=CELLULAR_AUTOMATA_ROW_START; m<= CELLULAR_AUTOMATA_ROW_END; m++ )
	 	 {
	 	 	for( n=CELLULAR_AUTOMATA_COLUMN_START; n<= CELLULAR_AUTOMATA_COLUMN_END; n++ )
	 	 	 {
			   	// If its a Biologicla Site inclrease count
	 	 	 	if( CA[m][n].isBiologicalCell() )
	 	 	 	 {
	 	 	 	 	totalNumberOfBC ++;

	 	 	 	 	if( CA[m][n].isCancerStemCell() )
	 	 	 	 	 {
	 	 	 	 	   totalNumberOfCSC++;
	 	 	 	 	 }
	 	 	 	 	else if( CA[m][n].isTransientAmplifyingCell())
	 	 	 	 	 {
	 	 	 	 	   totalNumberOfTAC++;
	 	 	 	 	   numberOfTACWithSpecificRemainingRoundsOfAmplification[ CA[m][n].getRemainingRoundsOfAmplification() ] ++ ;
	 	 	 	 	 }
	 	 	 	 	else if ( CA[m][n].isTerminallyDifferentiatedCell() )
	 	 	 	 	 {
	 	 	 	 	   totalNumberOfTDC++;
	 	 	 	 	   sumOfFiberDegradationPotentialOfTDC = sumOfFiberDegradationPotentialOfTDC + CA[m][n].getFiberDegradationPotential();
	 	 	 	 	 }
	 	 	 	 }
	 	 	 }
	 	 }

	 	this -> setTotalNumberOfBC(totalNumberOfBC) ;
	 	this -> setTotalNumberOfCSC(totalNumberOfCSC);
	 	this -> setTotalNumberOfTAC(totalNumberOfTAC);
	 	this -> setTotalNumberOfTDC(totalNumberOfTDC);

	 	for( int index=0; index<=10; index++ )
	 	 {
	 	   this -> setTotalNumberOfTACWithRemainingRoundsOfAmplification(index,numberOfTACWithSpecificRemainingRoundsOfAmplification[index]);
	 	 }

	 	this -> setSumOfFiberDegradationPotentialOfTDC(sumOfFiberDegradationPotentialOfTDC);

/*
	 	if( this -> getTotalNumberOfTDC() != 0 )
	 	 {

	 	   this -> setAverageOfFiberDegradationPotentialOfTDC( this -> getSumOfFiberDegradationPotentialOfTDC() / (double) this -> getTotalNumberOfTDC() );

            // calculate Standard Deviation Of Fiber Degradation Potential Of Biological Cell
            for( m=1; m<= ROWS; m++ )
             {
                for( n=1; n<= COLUMNS; n++ )
                 {
                    if( CA[m][n].isTerminallyDifferentiatedCell() )
                     {
                       sDOfDegradationPotentialOfTDC = sDOfDegradationPotentialOfTDC + pow ( CA[m][n].getFiberDegradationPotential() - this -> getAverageOfFiberDegradationPotentialOfTDC() , 2 ) ;
                     }
                 }
              }

	 	   this -> setStandardDeviationOfFiberDegradationPotentialOfTDC( sqrt ( sDOfDegradationPotentialOfTDC / this -> getTotalNumberOfTDC() )  );

	 	 }
*/
	 }
