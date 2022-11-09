/*****************************************************************************************************************************************************
*	Проект:Задание 12
*	Автор:Борисов Владислав И-428
******************************************************************************************************************************************************/
#ifndef __linux
#define cmdClean "cls"
#define cmdStop "pause"
#else
#define cmdClean "clear"
#define cmdStop "sleep 3"
#endif // __linux


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int k=5, botNum=1+rand()%100, playerNum=0;
    while(k!=0){
        system(cmdClean);
        printf("Количество попыток:%d\n", k);
        printf("Введите число от 1 до 100:");
        scanf("%d", &playerNum);
        if(playerNum>botNum){
            printf("Слишком много, попробуйте ещё раз.\n");
            k--;
            system(cmdStop);
        }
        else if(playerNum<botNum){
            printf("Слишком мало, попробуйте ещё раз.\n");
            k--;
            system(cmdStop);
        }
        else
            break;
    }
    if(k==0){
        system(cmdClean);
        printf("Попытки закончились.\n");
        system(cmdStop);
    }
    else if(k>0){
        system(cmdClean);
        printf("Вы угадали, поздравляем!\n");
        system(cmdStop);
    }
    return 0;
}
