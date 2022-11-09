/*****************************************************************************************************************************************************
*	Проект:Задание 10
*	Автор:Борисов Владислав И-428
******************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int maxLeight=0, temp=0, endStr=0;
    char *str;
    str=(char*) malloc(256*sizeof(char));
    printf("Enter the text:");
    fgets(str, 256, stdin);
    for(int i=0; str[i]!='\n'; i++)
        endStr++;
    if(str[endStr-1]!=' '){
        printf("There must be a space before the end of the text\n");
        return 0;
    }
    for(int i=0; str[i]!='\n'; i++){
        if(str[i]==' ' || str[i]=='\n'){
            if(temp>maxLeight)
                maxLeight=temp;
            temp=0;
        }
        else
            temp++;
    }
    printf("%d\n", maxLeight);
    return 0;
}
