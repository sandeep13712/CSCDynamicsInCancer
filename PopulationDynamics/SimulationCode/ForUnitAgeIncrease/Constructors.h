// File containing Constructor definitions

	// Constructor of class CellularAutomata initialising to default values
	CellularAutomata::CellularAutomata()
 	 {
 	 	// identity = id++;
 	 	// why not used - presence of padding of row and column , above , below and left , right respectively
 	 	// Cell starts at index 14 if above initialisation used

		type = ES;

 	 	age = 0;
		stiffness = 0;
		divisionRate = 0;
		size = 0;
		contractility = 0;
		invasiveness = 0;
		fiberDegradationPotential = 0;

		sensingRadius = 0;

		fiberDensity = 0;
		crossLinking = 0;

 	 }

	// Parameterised constructor
	// parameters -
	// type, age, stiffness, divisionRate, size, contractility, invasiveness, degradationPotential, sensingRadius, fiberDensity, crossLinking
	CellularAutomata::CellularAutomata( int type, float age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, int sensingRadius , float fiberDensity, float crossLinking)
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

		this->fiberDensity = fiberDensity;
		this->crossLinking = crossLinking;
 	 }

	// Parameterisied Constructor setting only Biological Cell properties
	// parameters -
	// type, age, stiffness, divisionRate, size, contractility, invasiveness, degradationPotential, sensingRadius
	CellularAutomata::CellularAutomata( int type, float age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, int sensingRadius)
 	 {
		this->type = type;

 	 	this->age  = age;
		this->stiffness = stiffness;
		this->divisionRate = divisionRate;
		this->size = size;
		this->contractility = contractility;
		this->invasiveness = invasiveness;
		this->fiberDegradationPotential = degradationPotential;

		this->sensingRadius = sensingRadius;
	 }

 	// Parameterisied Constructor setting only ECM site properties
 	// parameters -
	// int type, float fiberDensity, float crossLinking
	CellularAutomata::CellularAutomata( int type, float fiberDensity, float crossLinking)
 	 {

		this->type = type;

		this->fiberDensity = fiberDensity;
		this->crossLinking = crossLinking;
 	 }



//  Constructors for Class PropertiesOfBiologicalCellInNeighbourhood and PropertiesOfExtraCellularMatrixSiteInNeighbourhood
