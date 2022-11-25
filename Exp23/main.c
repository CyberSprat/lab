/*****************************************************************************************************************************************************
*   Проект:Задание 23
*   Автор:Борисов Владислав И-428
******************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int checkNum=0, n=0;
	printf("Enter string's count(0<n<1000):");
	scanf("%d", &n);
	if(n>0 && n<1000){
		int *mas;
		mas=(int*)malloc(n*sizeof(int));
		printf("Enter numbers:");
		for(int i=0; i<n; i++)
			scanf("%d", &mas[i]);
		printf("\nEnter number for check:");
		scanf("%d", &checkNum);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				if(i!=j)
					if(mas[i]*mas[j]==checkNum){
						printf("Yes\n");
						exit(0);
					}
				else
					continue;
			}
		free(mas);
		printf("No\n");
	}
	else{
		printf("\nn<0 or n>1000\n");
		exit(0);
	}
	return 0;
}