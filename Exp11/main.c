/*****************************************************************************************************************************************************
*	Проект:Задание 11
*	Автор:Борисов Владислав И-428
******************************************************************************************************************************************************/

//97-a, 65-A
#include "exp11.h"

int main(){
    char *text;
    char alph[2][26];
    enAlphGen(alph);
    text=(char*) malloc(256*sizeof(char));
    printf("Enter the text:");
    fgets(text, 256, stdin);
    enPanChecking(text, alph);
    return 0;
}
//abcdifghijklmnopqrstuvwxyz
