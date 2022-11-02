#ifndef EXP5_H
#define EXP5_H

#include <stdio.h>

int masIndividCheck(int *mas, int x){
    int mas_copy[x], individCount=0;
    for(int i=0; i<x; i++)
        mas_copy[i]=mas[i];
    for(int i=0; i<x; i++)
        if(mas_copy[i]==0){
            individCount++;
            break;
        }

    for(int i=0; i<x; i++)
        for(int j=0; j<x; j++){
            if(j!=i && mas_copy[i]==mas_copy[j])
                mas_copy[j]=0;
            else
                continue;
        }

    for(int i=0; i<x; i++)
        if(mas_copy[i]!=0)
            individCount++;
    return individCount;
}

#endif // EXP5_H
