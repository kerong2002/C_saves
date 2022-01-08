#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

void SetColor(int color = 7)
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}

int main(){
	int file_count=1;
	FILE *stream1=fopen("answer_output.txt", "r");
	FILE *stream2=fopen("classmates_output.txt", "r");
	char answer[999];
	char classmates[999];	
	while((fscanf(stream1, "%[^\n]", answer)!= EOF)and(fscanf(stream2, "%[^\n]", classmates)!= EOF))
	{
	    fgetc(stream1);
		fgetc(stream2); 
		if(!strcmp(answer , classmates)){
			SetColor(175);
		    printf("[NO.%d]pass\n\n",file_count);
		    SetColor(7);
		    file_count++;
		}
		if(strcmp(answer , classmates)){
			SetColor(207);
		    printf("[NO.%d]Output isn't currect :",file_count);
		    SetColor(7);
		    printf("%s\n",classmates);
		    SetColor(13);
			printf("The currect answer is this :");
			SetColor(7);
			printf("%s\n\n",answer);
			file_count++;
		}
//		printf("\n");
//	    printf(">%s \n",answer);
//	    printf(">%s \n",classmates);
		
	}

	fclose(stream1);
	fclose(stream2);
	return 0;
}

