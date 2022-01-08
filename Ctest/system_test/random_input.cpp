#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define testRUN 10
#define N_range 10
#define capital_english 65
#define lower_english 97
#define end_code 0

int main()
{
	FILE *pFileclear; 
	FILE *pFilewrite; 
	srand(time(NULL));
	pFileclear = fopen("input.txt","w");
	fprintf(pFileclear,"");
	fclose(pFileclear);
	for(int i=0;i<testRUN;i++)
	{
		pFilewrite = fopen("input.txt","a");
		int N = 1+rand()%N_range;
		fprintf(pFilewrite,"%d\n",N);
		for (int run=0;run<N;run++)
		{
			int size=1+rand()%5;
			for(int row=0;row<size;row++)
			{ 
				int capital=capital_english+rand()%25;
				int lower=lower_english+rand()%25;
				fprintf(pFilewrite,"%c",capital);
				fprintf(pFilewrite,"%c",lower);
			}
			fprintf(pFilewrite," ");
			if(run==N-1){
				fprintf(pFilewrite,"\n");
			}	
		}
		fclose(pFilewrite);
	}
	pFilewrite = fopen("input.txt","a");
	fprintf(pFilewrite,"%d",end_code);
	fclose(pFilewrite);
	return 0;
} 
