#ifndef FUFLO_H
#define FUFLO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef __linux

#include <conio.h>

#else
#include <unistd.h>
#include <termios.h>

int getch()

{

    int ch;

    struct termios oldt, newt;

    tcgetattr( STDIN_FILENO, &oldt );

    newt = oldt;

    newt.c_lflag &= ~( ICANON | ECHO );

    tcsetattr( STDIN_FILENO, TCSANOW, &newt );

    ch = getchar();

    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

    return ch;

}
#endif // __linux

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
		if(field[whiteRookY][i]==4 && (field[whiteRookY][i+1]!=2 || field[whiteRookY][i+1]!=0))
			return 0;
		else if(field[whiteRookY][i]==3)
			return 1;
	}
	for(int i=whiteRookX-1; i>=0; i--){
		if(field[whiteRookY][i]==4 && (field[whiteRookY][i-1]!=2 || field[whiteRookY][i-1]!=0))
			return 0;
		else if(field[whiteRookY][i]==3)
			return 1;
	}
	for(int i=whiteRookY+1; i<8; i++){
		if(field[i][whiteRookX]==4 && (field[i+1][whiteRookX]!=2 || field[i+1][whiteRookX]!=0))
			return 0;
		else if(field[i][whiteRookX]==3)
			return 1;
	}
	for(int i=whiteRookY-1; i>=0; i--){
		if(field[i][whiteRookX]==4 && (field[i-1][whiteRookX]!=2 || field[i-1][whiteRookX]!=0))
			return 0;
		else if(field[i][whiteRookX]==3)
			return 1;
	}
	return 0;
}

void bishopVSbishop_generation(int (*field)[8], int *whiteBishopX, int *whiteBishopY, int *blackBishopX, int *blackBishopY, int *goalX, int *goalY){
    srand(time(NULL));
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
			field[i][j]=0;
    *whiteBishopX=rand()%8;
    *whiteBishopY=rand()%8;
    *blackBishopX=rand()%8;
    *blackBishopY=rand()%8;
    *goalX=rand()%8;
	*goalY=rand()%8;
	field[*whiteBishopY][*whiteBishopX]=1;
	field[*blackBishopY][*blackBishopX]=2;
    field[*goalY][*goalX]=3;
    {
        int i=*blackBishopY+1, j=*blackBishopX+1;
        while(i<8 && j<8){
            if(field[i][j]!=1)
                field[i][j]=4;
            i++;
            j++;
        }
    }

    {
        int i=*blackBishopY-1, j=*blackBishopX-1;
        while(i>=0 && j>=0){
            if(field[i][j]!=1)
                field[i][j]=4;
            i--;
            j--;
        }
    }

    {
        int i=*blackBishopY+1, j=*blackBishopX-1;
        while(i<8 && j>=0){
            if(field[i][j]!=1)
                field[i][j]=4;
            i++;
            j--;
        }
    }

    {
        int i=*blackBishopY-1, j=*blackBishopX+1;
        while(i>=0 && j<8){
            if(field[i][j]!=1)
                field[i][j]=4;
            i--;
            j++;
        }
    }
}

int bishopVSbishop_action(int (*field)[8], int whiteBishopX, int whiteBishopY, int blackBishopX, int blackBishopY, int goalX, int goalY){
    {
        int i=whiteBishopY+1, j=whiteBishopX+1;
        while(i<8 && j<8){
            if(field[i][j]==4 && (field[i+1][j+1]!=2 || field[i+1][j+1]!=0))
                return 0;
            else if(field[i][j]==3)
                return 1;
            i++;
            j++;
        }
    }

    {
        int i=whiteBishopY-1, j=whiteBishopX-1;
        while(i>=0 && j>=0){
            if(field[i][j]==4 && (field[i-1][j-1]!=2 || field[i-1][j-1]!=0))
                return 0;
            else if(field[i][j]==3)
                return 1;
            i--;
            j--;
        }
    }

    {
        int i=whiteBishopY+1, j=whiteBishopX-1;
        while(i<8 && j>=0){
            if(field[i][j]==4 && (field[i+1][j-1]!=2 || field[i+1][j-1]!=0))
                return 0;
            else if(field[i][j]==3)
                return 1;
            i++;
            j--;
        }
    }

    {
        int i=whiteBishopY-1, j=whiteBishopX+1;
        while(i<8 && j<8){
            if(field[i][j]==4 && (field[i-1][j+1]!=2 || field[i-1][j+1]!=0))
                return 0;
            else if(field[i][j]==3)
                return 1;
            i--;
            j++;
        }
    }
}

void printMenuSelected_rookVSrook(char *cmdStr){
	system(cmdStr);
	printf(">Rook vs Rook\n");
	printf("Bishop vs Bishop\n");
}

void printMenuSelected_bishopVSbishop(char *cmdStr){
	system(cmdStr);
	printf("Rook vs Rook\n");
	printf(">Bishop vs Bishop\n");
}

#endif /*FUFLO_H*/
