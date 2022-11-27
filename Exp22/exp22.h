#ifndef EXP22_H
#define EXP22_H

#include <iostream>
#include <cstdlib>
#include <ctime>

void masGen(int (*mas)[5]){
    srand(time(NULL));
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            mas[i][j]=rand()%2;
}

std::string masCheck(int (*mas)[5]){
    if(mas[0][0]==1){
        if(mas[0][1]==1 || mas[1][1]==1 || mas[1][0]==1){
            return "NO";
        }
    }

    for(int i=1; i<4; i++){
        if(mas[0][i]==1)
            if(mas[0][i-1]==1 || mas[0][i+1]==1 || mas[1][i-1]==1 || mas[1][i]==1 || mas[1][i+1]==1){
                return "NO";
            }
    }
    if(mas[0][4]==1){
        if(mas[0][3]==1 || mas[1][3]==1 || mas[1][4]==1){
            return "NO";
        }
    }

    for(int i=1; i<4; i++){
        if(mas[i][0]==1)
            if(mas[i-1][0]==1 || mas[i+1][0]==1 || mas[i-1][1]==1 || mas[i][1]==1 || mas[i+1][1]==1){
                return "NO";
            }
    }

    for(int i=1; i<4; i++)
        for(int j=1; j<4; j++)
            if(mas[i][j]==1)
                if(mas[i-1][j-1]==1 || mas[i-1][j]==1 || mas[i-1][j+1]==1 || mas[i][j-1]==1 || mas[i][j+1]==1 || mas[i+1][j-1]==1 || mas[i+1][j]==1 || mas[i+1][j+1]==1){
                    return "NO";
                }

    for(int i=1; i<4; i++){
        if(mas[i][4]==1)
            if(mas[i-1][4]==1 || mas[i+1][4]==1 || mas[i-1][3]==1 || mas[i][3]==1 || mas[i+1][3]==1){
                return "NO";
            }
    }
    if(mas[4][0]==1){
        if(mas[4][1]==1 || mas[3][1]==1 || mas[3][0]==1){
            return "NO";
        }
    }

    for(int i=1; i<4; i++){
        if(mas[i][4]==1)
            if(mas[i-1][4]==1 || mas[i+1][4]==1 || mas[i-1][3]==1 || mas[i][3]==1 || mas[i+1][3]==1){
                return "NO";
            }
    }

    if(mas[4][4]==1){
        if(mas[4][3]==1 || mas[3][3]==1 || mas[3][4]==1){
            return "NO";
        }
    }
    return "YES";
}

void masOutput(int (*mas)[5]){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++)
            std::cout << mas[i][j];
        std::cout << "\n";
    }
}
#endif // EXP22_H
