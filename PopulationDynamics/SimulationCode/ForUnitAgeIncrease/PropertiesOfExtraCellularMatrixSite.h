// Class for properties of Properties Of Extra Cellular Matrix Site In Neighbourhood
// totalNumberOfESInNeighbourhood , sumOfFiberDensityInNeighbourhood , sumOfCrossLinkingInNeighbourhood

using namespace std;

class PropertiesOfExtraCellularMatrixSite
 {
   private:

   int totalFreeSpaceInNeighbourhood;

   int totalNumberOfESInNeighbourhood;              // Total Number Of ES In Neighbourhood

   float sumOfFiberDensityOfESInNeighbourhood;          // Sum Of Fiber Density Of Extra Cellular Matrix Site In Neighbourhood

   float sumOfCrossLinkingOfESInNeighbourhood;          // Sum Of Cross Linking Of Extra Cellular Matrix Site In Neighbourhood

   long int totalFreeSpace;

   long int totalNumberOfES;                             // Total Number Of ES

   double sumOfCrossLinkingOfES;                         // Sum Of Cross Linking Of Extra Cellular Matrix Site

   double sumOfFiberDensityOfES;                       // Total Fiber Density

   double averageOfFiberDensityOfES;                       // Average Fiber Density

   double standardDeviationOfFiberDensityOfES;             // Standard Deviation Of Fiber Density


   public:

   // Get and Set Function
   int getTotalFreeSpaceInNeighbourhood();

   void setTotalFreeSpaceInNeighbourhood( int );

   int getTotalNumberOfESInNeighbourhood();

   void setTotalNumberOfESInNeighbourhood( int );

   float getSumOfCrossLinkingInNeighbourhood();

   void setSumOfCrossLinkingInNeighbourhood( float );

   long int getTotalNumberOfES();

   void setTotalNumberOfES( long int );

   float getSumOfFiberDensityInNeighbourhood();

   void setSumOfFiberDensityInNeighbourhood( float );

   // Find the property values of Extra Cellular Matrix Site  In Neighbourhood of ( i, j )th Cell
   // parameters CellularAutomata CA[][12], int i, int j
   void caluclatePropertiesOfESInNeighbourhood( CellularAutomata[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER], int , int );


   long int getTotalFreeSpace();

   void setTotalFreeSpace( long int );

   double getSumOfFiberDensity();

   void setSumOfFiberDensity( double );

   double getSumOfCrossLinkingOfES();

   void setSumOfCrossLinkingOfES( double );

   double getAverageOfFiberDensityOfES();

   void setAverageOfFiberDensityOfES(double);

   double getStandardDeviationOfFiberDensityOfES();

   void setStandardDeviationOfFiberDensityOfES(double);

   void caluclatePropertiesOfES( CellularAutomata[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER] );

 };


 void PropertiesOfExtraCellularMatrixSite::caluclatePropertiesOfESInNeighbourhood( CellularAutomata CA[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER], int i, int j )
	 {
	 	int freeSpaceInNeighbourhood = 0;
	 	int totalNumberOfESInNeighbourhood = 0;
	 	double sumOfFiberDensityOfES = 0;
	 	float sumOfCrossLinking = 0;
	 	int m;
	 	int n;

	 	this -> setTotalFreeSpaceInNeighbourhood(0);
	 	this -> setTotalNumberOfESInNeighbourhood(0);
	 	this -> setSumOfCrossLinkingInNeighbourhood(0.0);
	 	this -> setSumOfFiberDensityInNeighbourhood(0);

	 	// For 8 Adjacent cells
	 	for( m=-1; m<2; m++ )
	 	 {
	 	 	for( n=-1; n<2; n++ )
	 	 	 {
			   	// If its a ECM Site inclrease counCA[0][0].writeResultsToFile(CA,x,y,rx,ry, randomNumber);t
	 	 	 	if( !( m==0 && n==0 ) && CA[i+m][j+n].isES()  )
	 	 	 	 {
	 	 	 	 	totalNumberOfESInNeighbourhood ++;
	 	 	 	 	sumOfFiberDensityOfES += CA[i+m][j+n].getFiberDensity();
                    sumOfCrossLinking += CA[i+m][j+n].getCrossLinking();

                    if( CA[i+m][j+n].getFiberDensity() == 0 )
                     {
                       freeSpaceInNeighbourhood++;
                     }
	 	 	 	 }
	 	 	 }
	 	 }

	 	 this -> setTotalFreeSpaceInNeighbourhood( freeSpaceInNeighbourhood );
	 	 this -> setTotalNumberOfESInNeighbourhood( totalNumberOfESInNeighbourhood );
	 	 this -> setSumOfFiberDensityInNeighbourhood( sumOfFiberDensityOfES );
	 	 this -> setSumOfCrossLinkingInNeighbourhood( sumOfCrossLinking );

	 }

 void PropertiesOfExtraCellularMatrixSite::caluclatePropertiesOfES( CellularAutomata CA[][COLUMNS_IN_CELLULAR_AUTOMATA_WITH_BUFFER] )
	 {
	 	long int totalFreeSpace = 0;
	 	long int totalNumberOfES = 0;
	 	double sumOfFiberDensityOfES = 0;
	 	double sDOfFiberDensityOfES = 0;

	 	double sumOfCrossLinking = 0;

	 	int m;
	 	int n;

	 	this -> setTotalFreeSpace(0);
	 	this -> setTotalNumberOfES( 0 ) ;
	 	this -> setSumOfFiberDensity( 0 ) ;
	 	this -> setAverageOfFiberDensityOfES( 0.0 );
	 	this -> setStandardDeviationOfFiberDensityOfES( 0.0 );

	 	this -> setSumOfCrossLinkingOfES( 0.0 );



        // For Entire Cellular Automata
	 	for( m=CELLULAR_AUTOMATA_ROW_START; m<= CELLULAR_AUTOMATA_ROW_END; m++ )
	 	 {
	 	 	for( n=CELLULAR_AUTOMATA_COLUMN_START; n<= CELLULAR_AUTOMATA_COLUMN_END; n++ )
	 	 	 {
			   	// If its a Biologicla Site inclrease count
	 	 	 	if( CA[m][n].isES() )
	 	 	 	 {
	 	 	 	 	totalNumberOfES ++;

	 	 	 	 	sumOfFiberDensityOfES += CA[m][n].getFiberDensity();

	 	 	 	 	sumOfCrossLinking += CA[m][n].getCrossLinking();

                    if( CA[m][n].getFiberDensity() == 0 )
                     {
                       totalFreeSpace++;
                     }
	 	 	 	 }
	 	 	 }
	 	 }

	 	this -> setTotalFreeSpace( totalFreeSpace );
	 	this -> setTotalNumberOfES( totalNumberOfES ) ;
	 	this -> setSumOfFiberDensity( sumOfFiberDensityOfES ) ;

	 	this -> setSumOfCrossLinkingOfES( sumOfCrossLinking );

/*
	 	if( this -> getTotalNumberOfES() != 0 )
	 	 {

	 	   this -> setAverageOfFiberDensityOfES ( (double) this -> getSumOfFiberDensity() / (double) this -> getTotalNumberOfES() );



            // calculate Standard Deviation Of Fiber Degradation Potential Of Biological Cell
            for( m=1; m<= ROWS; m++ )
             {
                for( n=1; n<= COLUMNS; n++ )
                 {
                    if( CA[m][n].isES() )
                     {
                       sDOfFiberDensityOfES = sDOfFiberDensityOfES + pow ( CA[m][n].getFiberDensity() - this -> getAverageOfFiberDensityOfES() , 2 ) ;
                     }
                 }
              }

	 	   this -> setStandardDeviationOfFiberDensityOfES( sqrt ( sDOfFiberDensityOfES / this -> getTotalNumberOfES() )  );

	 	 }
*/
	 }
