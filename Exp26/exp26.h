#ifndef EXP26_H
#define EXP26_H

#include <iostream>
#include <cstdlib>

void masTransp(int (*mas)[5], int (*masT)[5]){
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            masT[j][i]=mas[i][j];
}

std::string masSymetric(int (*mas)[5], int (*masT)[5]){
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(mas[i][j]!=masT[i][j])
                return "NO";
    return "YES";
}

#endif // EXP26_H
