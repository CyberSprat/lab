/*****************************************************************************************************************************************************
*   Проект:Задание 9
*   Автор:Борисов Владислав И-428
******************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int countA=0, countAn=0, countThe=0;
    char *str;
    str=(char*) malloc(256*sizeof(char));
    printf("Enter the text:");
    fgets(str, 256, stdin);
    for(int i=0; str[i]!='\n'; i++){
        if(i==0){
            if((str[i]=='A' || str[i]=='a') && str[i+1]==' ')
            countA++;
            else if((str[i]=='A' || str[i]=='a') && str[i+1]=='n' && str[i+2]==' ')
            countAn++;
            else if((str[i]=='T' || str[i]=='t') && str[i+1]=='h' && str[i+2]=='e' && str[i+3]==' ')
            countThe++;
        }
        else{
            if((str[i]=='A' || str[i]=='a') && str[i-1]==' ' && (str[i+1]==' ' || str[i+1]=='\n'))
                countA++;
            if((str[i]=='A' || str[i]=='a') && str[i+1]=='n' && str[i-1]==' ' && (str[i+2]==' ' || str[i+2]=='\n'))
                countAn++;
            if((str[i]=='T' || str[i]=='t') && str[i+1]=='h' && str[i+2]=='e' && (str[i+3]==' ' || str[i+3]=='\n') && str[i-1]==' ')
                countThe++;
        }
    }
    free(str);
    printf("Article \"a\":%d\nArticle \"an\":%d\nArticle \"the\":%d\n", countA, countAn, countThe);
    return 0;
}
