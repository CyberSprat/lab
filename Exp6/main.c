/*****************************************************************************************************************************************************
*   Проект:Задание 6
*   Автор:Борисов Владислав И-428
******************************************************************************************************************************************************/
#include <stdio.h>

int main(){
    unsigned int a=0, b=0, numWithMaxCount=0, count=0;
    printf("Enter natural nubers a and b(Note: a<b):");
    scanf("%d%d", &a, &b);
    if(a<b){
        int c=0;
        for(int i=a+1; i<b; i++){
            for(int j=1; j<=i; j++)
                if(i%j==0)
                    c++;
            if(c>count){
                count=c;
                numWithMaxCount=i;
            }
            c=0;
        }
        printf("%d:+%d", numWithMaxCount, count);
    }
    else
        printf("With a<b not OK.\n");
    return 0;
}
