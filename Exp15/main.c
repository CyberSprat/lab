/*****************************************************************************************************************************************************
*	Проект:Задание 15
*	Автор:Борисов Владислав И-428
******************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n=0;
    printf("Enter n:");
    scanf("%d", &n);
    int cube[n][n][n], startXYZ[3]={n+1,n+1,n+1}, endXYZ[3]={n+1,n+1,n+1};
    srand(time(NULL));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                cube[i][j][k]=rand()%2;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(startXYZ[0]==n+1 || startXYZ[1]==n+1 || startXYZ[2]==n+1){
                    startXYZ[0]=i;
                    startXYZ[1]=j;
                    startXYZ[2]=k;
                }
                if(cube[i][j][k]!=0){
                    startXYZ[0]=n+1;
                    startXYZ[1]=n+1;
                    startXYZ[2]=n+1;
                    endXYZ[0]=n+1;
                    endXYZ[1]=n+1;
                    endXYZ[2]=n+1;
                    break;
                }
                else{
                    endXYZ[0]=i;
                    endXYZ[1]=j;
                    endXYZ[2]=k;
                }
            }
            if(startXYZ[0]!=n+1 || startXYZ[1]!=n+1 || startXYZ[2]!=n+1 || endXYZ[0]!=n+1 || endXYZ[1]!=n+1 || endXYZ[2]!=n+1)
                printf("[%d;%d;%d][%d;%d;%d]\n", startXYZ[0], startXYZ[1], startXYZ[2], endXYZ[0], endXYZ[1], endXYZ[2]);
            startXYZ[0]=n+1;
            startXYZ[1]=n+1;
            startXYZ[2]=n+1;
            endXYZ[0]=n+1;
            endXYZ[1]=n+1;
            endXYZ[2]=n+1;
        }

    for(int i=0; i<n; i++)
        for(int k=0; k<n; k++){
            for(int j=0; j<n; j++){
                if(startXYZ[0]==n+1 || startXYZ[1]==n+1 || startXYZ[2]==n+1){
                    startXYZ[0]=i;
                    startXYZ[1]=j;
                    startXYZ[2]=k;
                }
                if(cube[i][j][k]!=0){
                    startXYZ[0]=n+1;
                    startXYZ[1]=n+1;
                    startXYZ[2]=n+1;
                    endXYZ[0]=n+1;
                    endXYZ[1]=n+1;
                    endXYZ[2]=n+1;
                    break;
                }
                else{
                    endXYZ[0]=i;
                    endXYZ[1]=j;
                    endXYZ[2]=k;
                }
            }
            if(startXYZ[0]!=n+1 || startXYZ[1]!=n+1 || startXYZ[2]!=n+1 || endXYZ[0]!=n+1 || endXYZ[1]!=n+1 || endXYZ[2]!=n+1)
                printf("[%d;%d;%d][%d;%d;%d]\n", startXYZ[0], startXYZ[1], startXYZ[2], endXYZ[0], endXYZ[1], endXYZ[2]);
            startXYZ[0]=n+1;
            startXYZ[1]=n+1;
            startXYZ[2]=n+1;
            endXYZ[0]=n+1;
            endXYZ[1]=n+1;
            endXYZ[2]=n+1;
        }

    for(int k=0; k<n; k++)
        for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                if(startXYZ[0]==n+1 || startXYZ[1]==n+1 || startXYZ[2]==n+1){
                    startXYZ[0]=i;
                    startXYZ[1]=j;
                    startXYZ[2]=k;
                }
                if(cube[i][j][k]!=0){
                    startXYZ[0]=n+1;
                    startXYZ[1]=n+1;
                    startXYZ[2]=n+1;
                    endXYZ[0]=n+1;
                    endXYZ[1]=n+1;
                    endXYZ[2]=n+1;
                    break;
                }
                else{
                    endXYZ[0]=i;
                    endXYZ[1]=j;
                    endXYZ[2]=k;
                }
            }
            if(startXYZ[0]!=n+1 || startXYZ[1]!=n+1 || startXYZ[2]!=n+1 || endXYZ[0]!=n+1 || endXYZ[1]!=n+1 || endXYZ[2]!=n+1)
                printf("[%d;%d;%d][%d;%d;%d]\n", startXYZ[0], startXYZ[1], startXYZ[2], endXYZ[0], endXYZ[1], endXYZ[2]);
            startXYZ[0]=n+1;
            startXYZ[1]=n+1;
            startXYZ[2]=n+1;
            endXYZ[0]=n+1;
            endXYZ[1]=n+1;
            endXYZ[2]=n+1;
        }

    return 0;
}
