#include "exp5.h"
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int masSize=0;
    printf("Enter array's size:");
    scanf("%d", &masSize);
    fflush(stdin);
    int mas[masSize];
    for(int i=0; i<masSize; i++)
        mas[i]=rand()%21-11;
     for(int i=0; i<masSize; i++)
        printf("%d ",mas[i]);
    printf("\nNot repided count:%d\n",  masIndividCheck(mas, masSize));
    return 0;
}
