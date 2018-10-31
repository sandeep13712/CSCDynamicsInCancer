#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* getfieldValue(char* line, int num)
{
   const char* tok;
   int temp = 0;

  //printf("Line: %s", line);
  tok = strtok (line," ");
  while (tok != NULL)
  {
    temp = temp+1;
    if(temp == num) return tok;
    tok = strtok (NULL," ");
  }

    return NULL;
}

void LoadState( int cells[][200])
 {
    FILE* stream = fopen("SimulationStep1400.txt", "r");

    char line[1024];
    int values[9];
    char dummy[50];

    int i=0;
    while (fgets(line, 1024, stream))
    {
	for(int j = 1; j<=200; j++)
	{
	char* tmp = strdup(line);
        sprintf(dummy,"%s",getfieldValue(tmp, j)); 
	free(tmp);
	cells[i][j-1] = atoi(dummy);
	}
        i=i+1;
    }

 }

int main_test()
{
	int cells[200][200];
	long int total = 0;

	for(int i = 0;i <200; i++)
	{
		for(int j=0;j<200;j++)
		{
			cells[i][j] = 0;
		}
	}

	LoadState(cells);

	FILE * fp = fopen("dem_main.txt","w");
	for(int i = 0; i<200; i++)
	{
		for(int j=0;j<200;j++)
		{
			fprintf(fp, "%d ", cells[i][j]);			
			total = total + cells[i][j];
		}
		
		fprintf(fp, "\n");
	}

	printf("Total: %ld", total);
}




