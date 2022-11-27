#ifndef EXP24-25_H
#define EXP24-25_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef __linux

#define ENTER 13
#define CMD "cls"

#include <conio.h>

#else
#include <unistd.h>
#include <termios.h>

#define ENTER 10
#define CMD "clear"

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

void exp24(int player, int bot){
	switch(player){
		case 1:
		switch(bot){
			case 1:
			printf("\nDraw\n");
			break;
			case 2:
			printf("\nBot win!\n");
			break;
			case 3:
			printf("\nPlayer win!\n");
			break;
		}
		break;
		case 2:
		switch(bot){
			case 1:
			printf("\nPlayer win!\n");
			break;
			case 2:
			printf("\nDraw!\n");
			break;
			case 3:
			printf("\nBot win!\n");
			break;
		}
		break;
		case 3:
		switch(bot){
			case 1:
			printf("\nBot win!\n");
			break;
			case 2:
			printf("\nPlayer win!\n");
			break;
			case 3:
			printf("\nDraw!\n");
			break;
		}
		break;
	}
}

void exp25(int player, int bot){
	switch(player){
		case 1:
		switch(bot){
			case 1:
			printf("\nDraw\n");
			break;
			case 2:
			printf("\nBot win!\n");
			break;
			case 3:
			printf("\nPlayer win!\n");
			break;
			case 4:
			printf("\nPlayer win!\n");
			break;
			case 5:
			printf("\nBot win!\n");
			break;
		}
		break;
		case 2:
		switch(bot){
			case 1:
			printf("\nPlayer win!\n");
			break;
			case 2:
			printf("\nDraw!\n");
			break;
			case 3:
			printf("\nBot win!\n");
			break;
			case 4:
			printf("\nBot win!\n");
			break;
			case 5:
			printf("\nPlayer win!\n");
			break;
		}
		break;
		case 3:
		switch(bot){
			case 1:
			printf("\nBot win!\n");
			break;
			case 2:
			printf("\nPlayer win!\n");
			break;
			case 3:
			printf("\nDraw!\n");
			break;
			case 4:
			printf("\nPlayer win!\n");
			break;
			case 5:
			printf("\nBot win!");
			break;
		}
		break;
		case 4:
		switch(bot){
			case 1:
			printf("\nBot win!\n");
			break;
			case 2:
			printf("\nPlayer win!\n");
			break;
			case 3:
			printf("\nBot win!\n");
			break;
			case 4:
			printf("\nDraw!\n");
			break;
			case 5:
			printf("\nPlayer win!");
			break;
		}
		break;
		case 5:
		switch(bot){
			case 1:
			printf("\nPlayer win!\n");
			break;
			case 2:
			printf("\nBot win!\n");
			break;
			case 3:
			printf("\nPlayer win!\n");
			break;
			case 4:
			printf("\nBot win!\n");
			break;
			case 5:
			printf("\nDraw!");
			break;
		}
		break;
	}
}

void menu(char *cmdStr){
	srand(time(NULL));
	int key=0, pSelect=0, bSelect=0, i=1;
	do{
		switch(i){
			case 1:
				system(cmdStr);
				printf(">Exp24\n");
				printf("Exp25\n");
				break;
			case 2:
				system(cmdStr);
				printf("Exp24\n");
				printf(">Exp25\n");
				break;
		}
		key=getch();
		if(key==115 && i>=1 && i<2)
			i++;
		else if(key==119 && i>1 && i<=2)
			i--;
	}while(key!=ENTER);
	switch(i){
		case 1:
			system(cmdStr);
			printf("1.Rock\n2.Papper\n3.Scissors\nPlease select:");
			scanf("%d", &pSelect);
			if(pSelect>=1 && pSelect<=3){
				bSelect=1+rand()%3;
				system(cmdStr);
				switch(pSelect){
                case 1:
                    printf("Player:Rock\n");
                    break;
                case 2:
                    printf("Player:Paper\n");
                    break;
                case 3:
                    printf("Player:Scissors\n");
                    break;
				}
				switch(bSelect){
                case 1:
                    printf("Bot:Rock\n");
                    break;
                case 2:
                    printf("Bot:Paper\n");
                    break;
                case 3:
                    printf("Bot:Scissors\n");
                    break;
				}
				exp24(pSelect, bSelect);
			}
			else
				exit(0);
			break;
		case 2:
			system(cmdStr);
			printf("1.Rock\n2.Papper\n3.Scissors\n4.Lizard\n5.Spok\nPlease select:");
			scanf("%d", &pSelect);
			if(pSelect>=1 && pSelect<=5){
				bSelect=1+rand()%5;
				system(cmdStr);
				switch(pSelect){
                case 1:
                    printf("Player:Rock\n");
                    break;
                case 2:
                    printf("Player:Paper\n");
                    break;
                case 3:
                    printf("Player:Scissors\n");
                    break;
                case 4:
                    printf("Player:Lizard\n");
                    break;
                case 5:
                    printf("Player:Spok\n");
                    break;
				}
				switch(bSelect){
                case 1:
                    printf("Bot:Rock\n");
                    break;
                case 2:
                    printf("Bot:Paper\n");
                    break;
                case 3:
                    printf("Bot:Scissors\n");
                    break;
                case 4:
                    printf("Bot:Lizard\n");
                    break;
                case 5:
                    printf("Bot:Spok\n");
                    break;
				}
				exp25(pSelect, bSelect);
			}
			else
				exit(0);
			break;
	}

}


#endif //EXP24-25_H
