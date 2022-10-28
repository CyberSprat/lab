#ifndef FUFLO_H
#define FUFLO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rookVSrook_generation(int (*field)[8], int *whiteRookX, int *whiteRookY, int *blackRookX, int *blackRookY, int *goalX, int *goalY){
	srand(time(NULL));
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
			field[i][j]=0;
	*whiteRookX=rand()%8;
	*whiteRookY=rand()%8;
	*blackRookX=rand()%8;
	*blackRookY=rand()%8;
	*goalX=rand()%8;
	*goalY=rand()%8;
	field[*whiteRookY][*whiteRookX]=1;
	field[*blackRookY][*blackRookX]=2;
	field[*goalY][*goalX]=3;
	for(int i=*blackRookX+1; i<8; i++){
		if(field[*blackRookY][i]!=1)
			field[*blackRookY][i]=4;
		else
			break;
	}
	for(int i=*blackRookX-1; i>=0; i--){
		if(field[*blackRookY][i]!=1)
			field[*blackRookY][i]=4;
		else
			break;
	}
	for(int i=*blackRookY+1; i<8; i++){
		if(field[i][*blackRookX]!=1)
			field[i][*blackRookX]=4;
		else
			break;
	}
	for(int i=*blackRookY-1; i>=0; i--){
		if(field[i][*blackRookX]!=1)
			field[i][*blackRookX]=4;
		else
			break;
	}
}

int rookVSrook_action(int (*field)[8], int whiteRookX, int whiteRookY, int blackRookX, int blackRookY, int goalX, int goalY){
	for(int i=whiteRookX+1; i<8; i++){
		if(field[whiteRookY][i]==4 && field[whiteRookY][i+1]!=2)
			return 0;
		else if(field[whiteRookY][i]==3)
			return 1;
	}
	for(int i=whiteRookX-1; i>=0; i--){
		if(field[whiteRookY][i]==4 && field[whiteRookY][i-1]!=2)
			return 0;
		else if(field[whiteRookY][i]==3)
			return 1;
	}
	for(int i=whiteRookY+1; i<8; i++){
		if(field[i][whiteRookX]==4 && field[i+1][whiteRookX]!=2)
			return 0;
		else if(field[i][whiteRookX]==3)
			return 1;
	}
	for(int i=whiteRookY-1; i>=0; i--){
		if(field[i][whiteRookX]==4 && field[i-1][whiteRookX]!=2)
			return 0;
		else if(field[i][whiteRookX]==3)
			return 1;
	}
	return 0;
}

#endif /*FUFLO_H*/