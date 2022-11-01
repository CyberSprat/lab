#ifndef SUCKER_H
#define SUCKER_H

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

#include <stdio.h>
#include <stdlib.h>

void v1_checking(char *str){
	int strWeight=0, numCount=0;
	for(int i=0; str[i]!='\0'; i++)
		strWeight++;
	if(strWeight==12 && str[3]=='-' && str[7]=='-'){
		for(int i=0; i<12; i++){
			if(i==3 || i==7)
				continue;
			else{
				for(int j=0; j<10; j++){
					if(str[i]==48+j)
						numCount++;
				}
			}
		}
		if(numCount==10)
			printf("%s is correct phone\'s number\n", str);
		else
			printf("%s is uncorrect phone\'s number\n",str);
	}
	else
		printf("%s is uncorrect phone\'s number\n",str);
}

void v2_checking(char *str){
	int strWeight=0, numCount=0;
	for(int i=0; str[i]!='\0'; i++)
		strWeight++;
	if(strWeight==14 && str[0]=='7' && str[1]=='-' && str[5]=='-' && str[9]=='-'){
		for(int i=0; i<14; i++){
			if(i==1 || i==5 || i==9)
				continue;
			else{
				for(int j=0; j<10; j++){
					if(str[i]==48+j)
						numCount++;
				}
			}
		}
		if(numCount==11)
			printf("%s is correct phone\'s number\n", str);
		else
			printf("%s is uncorrect phone\'s number\n",str);
	}
	else
		printf("%s is uncorrect phone\'s number\n",str);
}

#endif //SUCKER_H