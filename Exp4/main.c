#include "sucker.h"


int main(){
	char mainStr[15];
	printf("Enter the phone\'s number(Epxamples:7-123-456-7890; 123-456-7890):");
	scanf("%s", mainStr);
	fflush(stdin);
	mainStr[14]='\0';
	if(mainStr[0]!='7')
		v1_checking(mainStr);
	else
		v2_checking(mainStr);
	printf("Press any buttom for Exit...\n");
	int a=getch();
	return 0;
}