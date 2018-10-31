const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");tok && *tok;tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}


void setUpParameters( double *ALPHA, int *BETA, int *GAMMA, int *STATE_OF_FIBER_DENSITY_FOR_CSC_OR_TAC_TO_REPLICATE,
                         int *STATE_OF_FIBER_DENSITY_FOR_BIOLOGICAL_CELL_TO_MOVE, double *FIBERDENSITY, int *DOUBLINGTIME,
                         int *SIMULATION_STEPS, double *MU, double *SIGMA, double *LAMBDA )
 {
    FILE* stream = fopen("Cell_Heterogeneity.conf", "r");

    char line[1024];
    int values[9];
    float floatValues[3];
    char dummy[50];

    int i=0;
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        sprintf(dummy,"%s",getfield(tmp, 2));
        if(i<=5)
            {
                values[i] = atoi(dummy);
            }
        else
            {
                floatValues[i-6]= atof(dummy);
            }

        free(tmp);
        i=i+1;
    }

	*STATE_OF_FIBER_DENSITY_FOR_CSC_OR_TAC_TO_REPLICATE = values[0];
	*STATE_OF_FIBER_DENSITY_FOR_BIOLOGICAL_CELL_TO_MOVE = values[0];

	*FIBERDENSITY = values[1];

	*DOUBLINGTIME = values[2];

	*SIMULATION_STEPS = values[3];
	*BETA = values[4];

	*GAMMA = values[5];
	*LAMBDA = floatValues[0];

	*ALPHA = floatValues[1];

	*SIGMA = floatValues[2];

    *MU = floatValues[3];
 }
