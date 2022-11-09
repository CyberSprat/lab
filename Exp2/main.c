/*****************************************************************************************************************************************************
*	Проект:Задание 2
*	Автор:Борисов Владислав И-428
******************************************************************************************************************************************************/
#include "fuflo.h"

void menu(int (*field)[8], char *strCmd);

int main(){
    int chessPlank[8][8];
    menu(chessPlank, "cls");
	return 0;
}

void menu(int (*field)[8], char *strCmd){
	int key=0, i=1, result=0;
	int x1=0, y1=0, x2=0, y2=0, x3=0, y3=0;
	do{
		switch(i){
			case 1:
				printMenuSelected_rookVSrook(strCmd);
				break;
			case 2:
				printMenuSelected_bishopVSbishop(strCmd);
				break;
		}
		key=getch();
		if(key==115 && i>=1 && i<2)
			i++;
		else if(key==119 && i>1 && i<=2)
			i--;
	}while(key!=13);
	switch(i){
		case 1:
			rookVSrook_generation(field, &x1, &y1, &x2, &y2, &x3, &y3);
			result=rookVSrook_action(field, x1, y1, x2, y2, x3, y3);
			if(result==1){
                system(strCmd);
                printf("This generation is success.\n\nPress any buttom for exit...");
                key=getch();
			}
			else{
                system(strCmd);
                printf("This generation is fail.\n\nPress any buttom for exit...");
                key=getch();
			}
			break;
		case 2:
            bishopVSbishop_generation(field, &x1, &y1, &x2, &y2, &x3, &y3);
            bishopVSbishop_action(field, x1, y1, x2, y2, x3, y3);
            if(result==1){
                system(strCmd);
                printf("This generation is success.\n\nPress any buttom for exit...");
                key=getch();
			}
			else{
                system(strCmd);
                printf("This generation is fail.\n\nPress any buttom for exit...");
                key=getch();
			}
			break;
	}
}
