#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	FILE *stream1=fopen("read1.txt", "r");
	FILE *stream2=fopen("read2.txt", "r");
	char line1[99];
	char line2[99];	
	while((fscanf(stream1, "%[^\n]", line1)!= EOF)and(fscanf(stream2, "%[^\n]", line2)!= EOF))
	{
	    fgetc(stream1);
		fgetc(stream2); 
		if(!strcmp(line1, line2)){
		    printf("pass\n");
		}
		if(strcmp(line1, line2)){
		    printf("%s This output is not currect. Currect answer is %s\n",line2,line1);
		}
//	    printf(">%s \n",line1);
//	    printf(">%s \n",line2);
		
	}

	fclose(stream1);
	fclose(stream2);
	return 0;
}

