// File containing Get and Set functions of classes

using namespace std;

 //Getters and Setters of class CellularAutomata

/*	int CellularAutomata::getRows()
 	 {
	  return rows;
 	 }

	void CellularAutomata::setRows(int r)
	 {
	 	rows = r;
	 }

	int CellularAutomata::getColumns()
 	 {
 	 	return columns;
 	 }

	void CellularAutomata::setColumns(int c)
	 {
	 	columns = c;
	 } */

	double CellularAutomata::getNumberOfFibersDegradedByBC( )
	 {
       return numberOfFibersDegradedByBC;
	 }

	void CellularAutomata::setNumberOfFibersDegradedByBC( double totalNumberOfFibersDegradedByBC )
	 {
	   numberOfFibersDegradedByBC = totalNumberOfFibersDegradedByBC;
	 }

	double CellularAutomata::getNumberOfFibersReplacedByBC( )
	 {
       return numberOfFibersReplacedByBC;
	 }

	void CellularAutomata::setNumberOfFibersReplacedByBC( double totalNumberOfFibersReplacedByBC )
	 {
	   numberOfFibersReplacedByBC = totalNumberOfFibersReplacedByBC;
	 }



	double CellularAutomata::getNumberOfFibersDegradedByCSC()
	 {
	   return numberOfFibersDegradedByCSC;
	 }

	void CellularAutomata::setNumberOfFibersDegradedByCSC( double totalNumberOfFibersDegradedByCSC )
	 {
	   numberOfFibersDegradedByCSC = totalNumberOfFibersDegradedByCSC;
	 }

    double CellularAutomata::getNumberOfFibersReplacedByCSC()
     {
       return numberOfFibersReplacedByCSC;
     }

    void CellularAutomata::setNumberOfFibersReplacedByCSC( double fibersReplacedByCSC )
     {
       numberOfFibersReplacedByCSC = fibersReplacedByCSC;
     }



	double CellularAutomata::getNumberOfFibersDegradedByTAC()
	 {
	   return numberOfFibersDegradedByTAC;
	 }

	void CellularAutomata::setNumberOfFibersDegradedByTAC( double totalNumberOfFibersDegradedByTAC )
	 {
       numberOfFibersDegradedByTAC = totalNumberOfFibersDegradedByTAC;
	 }

    double CellularAutomata::getNumberOfFibersReplacedByTAC()
     {
       return numberOfFibersReplacedByTAC;
     }

    void CellularAutomata::setNumberOfFibersReplacedByTAC( double fibersReplacedByTAC )
     {
       numberOfFibersReplacedByTAC = fibersReplacedByTAC;
     }


    double CellularAutomata::getNumberOfFibersDegradedByTDC()
     {
       return numberOfFibersDegradedByTDC;
     }

    void CellularAutomata::setNumberOfFibersDegradedByTDC( double fibersDegradedByTDC )
     {
       numberOfFibersDegradedByTDC = fibersDegradedByTDC;
     }

    double CellularAutomata::getNumberOfFibersReplacedByTDC()
     {
       return numberOfFibersReplacedByTDC;
     }

    void CellularAutomata::setNumberOfFibersReplacedByTDC( double fibersReplacedByTDC )
     {
       numberOfFibersReplacedByTDC = fibersReplacedByTDC;
     }

	int CellularAutomata::getIdentity()
	 {
	 	return(identity);
	 }

	void CellularAutomata::setIdentity(int i)
	 {
	 	identity = i;
	 }

	int CellularAutomata::getType()
	 {
	 	return(type);
	 }

	void CellularAutomata::setType(int typeOfCell)
	 {
	 	type = typeOfCell;
	 }

	bool CellularAutomata::isBiologicalCell()
	 {
	 	return( ( getType() == CSC ) || ( getType() == TAC ) || ( getType() == TDC) );
	 }

 	bool CellularAutomata::isES()
	 {
	 	return( getType() == ES );
	 }

	bool CellularAutomata::isCancerStemCell()
	 {
	 	return( getType() == CSC );
	 }

	bool CellularAutomata::isTransientAmplifyingCell()
	 {
	 	return( getType() == TAC );
	 }

	bool CellularAutomata::isTerminallyDifferentiatedCell()
	 {
	 	return( getType() == TDC );
	 }

	float CellularAutomata::getAge()
	 {
	 	return(age);
	 }

	void CellularAutomata::setAge( float ageOfCell)
	 {
	 	age = ageOfCell;
	 }

	float CellularAutomata::getStiffness()
	 {
	 	return stiffness;
	 }

	void CellularAutomata::setStiffness( float stiffnessOfCell )
	 {
	 	stiffness = stiffnessOfCell;
	 }

	float CellularAutomata::getDivisionRate( )
	 {
	 	return divisionRate;
	 }

	void CellularAutomata::setDivisionRate( float divisionRateOfCell )
	 {
	 	divisionRate = divisionRateOfCell;
	 }

	int CellularAutomata::getSize()
	 {
	 	return size;
	 }

	void CellularAutomata::setSize( int sizeOfCell )
	 {
	 	size = sizeOfCell;
	 }

	float CellularAutomata::getContractility()
	 {
	 	return contractility;
	 }

	void CellularAutomata::setContractility( float contractilityOfCell )
	 {
	 	contractility = contractilityOfCell;
	 }

	void CellularAutomata::setInvasiveness( float invasivenessOfCell )
	 {
	 	invasiveness = invasivenessOfCell;
	 }

	float CellularAutomata::getInvasiveness()
	 {
	 	return invasiveness;
	 }

	void CellularAutomata::setFiberDegradationPotential( float fiberDegradationPotentialOfCell )
	 {
	 	fiberDegradationPotential = fiberDegradationPotentialOfCell;
	 }

	float CellularAutomata::getFiberDegradationPotential()
	 {
	 	return fiberDegradationPotential;
	 }

	int CellularAutomata::getSensingRadius()
	 {
	 	return sensingRadius;
	 }

	void CellularAutomata::setSensingRadius( int sensingRadiusOfCell )
	 {
	 	sensingRadius = sensingRadiusOfCell;
	 }

	int CellularAutomata::getRemainingRoundsOfAmplification()
	 {
	   return remainingRoundsOfAmplification;
	 }

	void CellularAutomata::setRemainingRoundsOfAmplification(int numberOfAmplification )
	 {
	   remainingRoundsOfAmplification = numberOfAmplification;
	 }

	int CellularAutomata::getBeta()
	 {
	   return beta;
	 }

	void CellularAutomata::setBeta( int betaOfTAC )
	 {
	   beta = betaOfTAC;
	 }

	float CellularAutomata::getFiberDensity()
	 {
	 	return fiberDensity;
	 }

	void CellularAutomata::setFiberDensity( float fiberDensityOfES )
	 {
	 	fiberDensity = fiberDensityOfES;
	 }

	float CellularAutomata::getCrossLinking()
	 {
	 	return crossLinking;
	 }

	void CellularAutomata::setCrossLinking( float crossLiningOfES )
	 {
	 	crossLinking = crossLiningOfES;
	 }


 //Getters and Setters of class PropertiesOfBiologicalCellInNeighbourhood

   int PropertiesOfBiologicalCell::getTotalNumberOfBCInNeighbourhood()
    {
      return totalNumberOfBCInNeighbourhood;
    }

   void PropertiesOfBiologicalCell::setTotalNumberOfBCInNeighbourhood( int numberOfBCInNeighbourhood )
    {
      totalNumberOfBCInNeighbourhood = numberOfBCInNeighbourhood;
    }

   int PropertiesOfBiologicalCell::getTotalNumberOfCSCInNeighbourhood()
    {
     return totalNumberOfCSCInNeighbourhood;
    }

   void PropertiesOfBiologicalCell::setTotalNumberOfCSCInNeighbourhood( int numberOfCSCInNeighbourhood )
    {
      totalNumberOfCSCInNeighbourhood = numberOfCSCInNeighbourhood;
    }

   int PropertiesOfBiologicalCell::getTotalNumberOfTACInNeighbourhood()
    {
      return totalNumberOfTACInNeighbourhood;
    }

   void PropertiesOfBiologicalCell::setTotalNumberOfTACInNeighbourhood( int numberOfTACInNeighbourhood )
    {
      totalNumberOfTACInNeighbourhood = numberOfTACInNeighbourhood;
    }


   int PropertiesOfBiologicalCell::getTotalNumberOfTDCInNeighbourhood()
    {
     return totalNumberOfTDCInNeighbourhood;
    }

   void PropertiesOfBiologicalCell::setTotalNumberOfTDCInNeighbourhood( int numberOfTDCInNeighbourhood )
    {
     totalNumberOfTDCInNeighbourhood = numberOfTDCInNeighbourhood;
    }

   long int PropertiesOfBiologicalCell::getTotalNumberOfTACWithRemainingRoundsOfAmplification( int index )
    {
      return( totalNumberOfTACWithRemainingRoundsOfAmplification[index] );
    }

   long int PropertiesOfBiologicalCell::setTotalNumberOfTACWithRemainingRoundsOfAmplification( int index, long int countOfTACWithIndexnumberOfRemainingROundsOfAmplification )
    {
      totalNumberOfTACWithRemainingRoundsOfAmplification[index] = countOfTACWithIndexnumberOfRemainingROundsOfAmplification;
    }

   float PropertiesOfBiologicalCell::getSumOfFiberDegradationPotentialOfBCInNeighbourhood()
    {
      return sumOfFiberDegradationPotentialOfBCInNeighbourhood;
    }

   void PropertiesOfBiologicalCell::setSumOfFiberDegradationPotentialOfBCInNeighbourhood( float totalFiberDegradationPotentialOfBCInNeighbourhood )
    {
      sumOfFiberDegradationPotentialOfBCInNeighbourhood = totalFiberDegradationPotentialOfBCInNeighbourhood;
    }

   float PropertiesOfBiologicalCell::getAverageOfFiberDegradationPotentialOfBCInNeighbourhood()
    {
      return averageOfFiberDegradationPotentialOfBCInNeighbourhood;
    }

   void PropertiesOfBiologicalCell::setAverageOfFiberDegradationPotentialOfBCInNeighbourhood( float averageFiberDegradationPotentialOfBCInNeighbourhood )
    {
      averageOfFiberDegradationPotentialOfBCInNeighbourhood = averageFiberDegradationPotentialOfBCInNeighbourhood;
    }


   float PropertiesOfBiologicalCell::getSumOfFiberDegradationPotentialOfCSCInNeighbourhood()
    {
      return sumOfFiberDegradationPotentialOfCSCInNeighbourhood;
    }

   void PropertiesOfBiologicalCell::setSumOfFiberDegradationPotentialOfCSCInNeighbourhood( float totalFiberDegradationPotentialOfCSCInNeighbourhood )
    {
      sumOfFiberDegradationPotentialOfCSCInNeighbourhood = totalFiberDegradationPotentialOfCSCInNeighbourhood;
    }

   float PropertiesOfBiologicalCell::getAverageOfFiberDegradationPotentialOfCSCInNeighbourhood()
    {
      return averageOfFiberDegradationPotentialOfCSCInNeighbourhood;
    }

   void PropertiesOfBiologicalCell::setAverageOfFiberDegradationPotentialOfCSCInNeighbourhood( float averageFiberDegradationPotentialOfCSCInNeighbourhood )
    {
      averageOfFiberDegradationPotentialOfCSCInNeighbourhood = averageFiberDegradationPotentialOfCSCInNeighbourhood;
    }


   float PropertiesOfBiologicalCell::getSumOfFiberDegradationPotentialOfTACInNeighbourhood()
    {
      return sumOfFiberDegradationPotentialOfTACInNeighbourhood;
    }

   void PropertiesOfBiologicalCell::setSumOfFiberDegradationPotentialOfTACInNeighbourhood( float totalFiberDegradationPotentialOfTACInNeighbourhood )
    {
      sumOfFiberDegradationPotentialOfTACInNeighbourhood = totalFiberDegradationPotentialOfTACInNeighbourhood;
    }

   float PropertiesOfBiologicalCell::getAverageOfFiberDegradationPotentialOfTACInNeighbourhood()
    {
      return averageOfFiberDegradationPotentialOfTACInNeighbourhood;
    }

   void PropertiesOfBiologicalCell::setAverageOfFiberDegradationPotentialOfTACInNeighbourhood( float averageFiberDegradationPotentialOfTACInNeighbourhood )
    {
      averageOfFiberDegradationPotentialOfTACInNeighbourhood = averageFiberDegradationPotentialOfTACInNeighbourhood;
    }


   float PropertiesOfBiologicalCell::getSumOfFiberDegradationPotentialOfTDCInNeighbourhood()
    {
     return sumOfFiberDegradationPotentialOfTDCInNeighbourhood;
    }

   void PropertiesOfBiologicalCell::setSumOfFiberDegradationPotentialOfTDCInNeighbourhood( float summationOfDegradationPotentialOfTDCInNeighbourhood )
    {
     sumOfFiberDegradationPotentialOfTDCInNeighbourhood = summationOfDegradationPotentialOfTDCInNeighbourhood;
    }


   float PropertiesOfBiologicalCell::getAverageOfFiberDegradationPotentialOfTDCInNeighbourhood()
    {
      return averageOfFiberDegradationPotentialOfTDCInNeighbourhood;
    }

   void PropertiesOfBiologicalCell::setAverageOfFiberDegradationPotentialOfTDCInNeighbourhood( float avgOfFiberDegradationPotentialOfTDCInNeighbourhood )
    {
      averageOfFiberDegradationPotentialOfTDCInNeighbourhood = avgOfFiberDegradationPotentialOfTDCInNeighbourhood;
    }


   long int PropertiesOfBiologicalCell::getTotalNumberOfBC()
    {
     return totalNumberOfBC;
    }

   void PropertiesOfBiologicalCell::setTotalNumberOfBC( long int numberOfBC )
    {
     totalNumberOfBC = numberOfBC;
    }

   long int PropertiesOfBiologicalCell::getTotalNumberOfCSC()
    {
     return totalNumberOfCSC;
    }

   void PropertiesOfBiologicalCell::setTotalNumberOfCSC( long int numberOfCSC )
    {
     totalNumberOfCSC = numberOfCSC;
    }

   long int PropertiesOfBiologicalCell::getTotalNumberOfTAC()
    {
     return totalNumberOfTAC;
    }

   void PropertiesOfBiologicalCell::setTotalNumberOfTAC( long int numberOfTAC )
    {
     totalNumberOfTAC = numberOfTAC;
    }

   long int PropertiesOfBiologicalCell::getTotalNumberOfTDC()
    {
     return totalNumberOfTDC;
    }

   void PropertiesOfBiologicalCell::setTotalNumberOfTDC( long int numberOfTDC )
    {
     totalNumberOfTDC = numberOfTDC;
    }

   double PropertiesOfBiologicalCell::getSumOfFiberDegradationPotentialOfTDC()
    {
     return sumOfFiberDegradationPotentialOfTDC;
    }

   void PropertiesOfBiologicalCell::setSumOfFiberDegradationPotentialOfTDC( double summationOfDegradationPotentialOfTDC )
    {
     sumOfFiberDegradationPotentialOfTDC = summationOfDegradationPotentialOfTDC;
    }

   void PropertiesOfBiologicalCell::setAverageOfFiberDegradationPotentialOfTDC( double avgOfFiberDegradationPotentialOfTDC )
    {
      averageOfFiberDegradationPotentialOfTDC = avgOfFiberDegradationPotentialOfTDC;
    }

   double PropertiesOfBiologicalCell::getAverageOfFiberDegradationPotentialOfTDC()
    {
      return averageOfFiberDegradationPotentialOfTDC;
    }

   void PropertiesOfBiologicalCell::setStandardDeviationOfFiberDegradationPotentialOfTDC( double sDOfFiberDegradationPotentialOfTDC )
    {
      standardDeviationOfFiberDegradationPotentialOfTDC = sDOfFiberDegradationPotentialOfTDC;
    }

   double PropertiesOfBiologicalCell::getStandardDeviationOfFiberDegradationPotentialOfTDC()
    {
      return standardDeviationOfFiberDegradationPotentialOfTDC;
    }


 //Getters and Setters of class PropertiesOfExtraCellularMatrixSiteInNeighbourhood

   int PropertiesOfExtraCellularMatrixSite::getTotalFreeSpaceInNeighbourhood()
    {
      return totalFreeSpaceInNeighbourhood;
    }

   void PropertiesOfExtraCellularMatrixSite::setTotalFreeSpaceInNeighbourhood( int freeSpaceInNeighbourhood )
    {
      totalFreeSpaceInNeighbourhood = freeSpaceInNeighbourhood;
    }

   int PropertiesOfExtraCellularMatrixSite::getTotalNumberOfESInNeighbourhood()
    {
     return totalNumberOfESInNeighbourhood;
    }

   void PropertiesOfExtraCellularMatrixSite::setTotalNumberOfESInNeighbourhood( int numberOfESInNeighbourhood )
    {
     totalNumberOfESInNeighbourhood = numberOfESInNeighbourhood;
    }

   float PropertiesOfExtraCellularMatrixSite::getSumOfCrossLinkingInNeighbourhood()
    {
      return sumOfCrossLinkingOfESInNeighbourhood;
    }

   void PropertiesOfExtraCellularMatrixSite::setSumOfCrossLinkingInNeighbourhood( float summationOfCrossLinkingInNeighbourhood )
    {
      sumOfCrossLinkingOfESInNeighbourhood = summationOfCrossLinkingInNeighbourhood;
    }

   float PropertiesOfExtraCellularMatrixSite::getSumOfFiberDensityInNeighbourhood()
    {
      return sumOfFiberDensityOfESInNeighbourhood;
    }

   void PropertiesOfExtraCellularMatrixSite::setSumOfFiberDensityInNeighbourhood( float summationOfFiberDensityInNeighbourhood)
    {
      sumOfFiberDensityOfESInNeighbourhood = summationOfFiberDensityInNeighbourhood;
    }

   int getTotalFreeSpaceInNeighbourhood();

   void setTotalFreeSpaceInNeighbourhood( int );

   long int PropertiesOfExtraCellularMatrixSite::getTotalNumberOfES()
    {
     return totalNumberOfES;
    }

   void PropertiesOfExtraCellularMatrixSite::setTotalNumberOfES( long int numberOfES )
    {
     totalNumberOfES = numberOfES;
    }

   double PropertiesOfExtraCellularMatrixSite::getSumOfCrossLinkingOfES()
    {
      return sumOfCrossLinkingOfES;
    }

   void  PropertiesOfExtraCellularMatrixSite::setSumOfCrossLinkingOfES( double totalCrossLinkingOfES )
    {
      sumOfCrossLinkingOfES = totalCrossLinkingOfES;
    }

   long int PropertiesOfExtraCellularMatrixSite::getTotalFreeSpace()
    {
      return totalFreeSpace;
    }

   void PropertiesOfExtraCellularMatrixSite::setTotalFreeSpace( long int freeSpace )
    {
      totalFreeSpace = freeSpace;
    }

   double PropertiesOfExtraCellularMatrixSite::getSumOfFiberDensity()
    {
      return sumOfFiberDensityOfES;
    }

   void PropertiesOfExtraCellularMatrixSite::setSumOfFiberDensity( double summationOfFiberDensity)
    {
      sumOfFiberDensityOfES = summationOfFiberDensity;
    }

   double PropertiesOfExtraCellularMatrixSite::getAverageOfFiberDensityOfES()
    {
      return averageOfFiberDensityOfES;
    }

   void PropertiesOfExtraCellularMatrixSite::setAverageOfFiberDensityOfES( double avgOfFiberDensityOfES )
    {
      averageOfFiberDensityOfES = avgOfFiberDensityOfES;
    }

   double PropertiesOfExtraCellularMatrixSite::getStandardDeviationOfFiberDensityOfES()
    {
      return standardDeviationOfFiberDensityOfES;
    }

   void PropertiesOfExtraCellularMatrixSite::setStandardDeviationOfFiberDensityOfES( double sDOfFiberDensityOfES )
    {
      standardDeviationOfFiberDensityOfES = sDOfFiberDensityOfES;
    }
