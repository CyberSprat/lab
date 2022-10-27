#include "ebobo.h"
#include <conio.h>

void menu(circle v, float *dot1, float *dot2, char *strCmd);

int main(){
	circle v7;
	float Dot1[2], Dot2[2];
	printf("Enter x and y dot A:");
	scanf("%f%f", &Dot1[0], &Dot1[1]);
	printf("Enter x and y dot B:");
	scanf("%f%f", &Dot2[0], &Dot2[1]);
	coordZoneA(v7.zoneAX, v7.zoneAY);
	coordZoneB(v7.zoneBX, v7.zoneBY);
	coordZoneC(v7.zoneCX, v7.zoneCY);
	coordZoneD(v7.zoneDX, v7.zoneDY);
	menu(v7, Dot1, Dot2, "cls");
	return 0;
}

void menu(circle v, float *dot1, float *dot2, char *strCmd){
	int key=0, i=1;
	do{
		switch(i){
			case 1:
				printMenuSelected_checkingDotInZones(strCmd);
				break;
			case 2:
				printMenuSelected_directionChecking(strCmd);
				break;
			case 3:
				printMenuSelected_dotInBorderChecking(strCmd);
				break;
			case 4:
				printMenuSelected_dotCCheckingOnAB(strCmd);
				break;
		}
		key=getch();
		if(key==115 && i>=1 && i<4)
			i++;
		else if(key==119 && i>1 && i<=4)
			i--;
	}while(key!=13);
	switch(i){
		case 1:
			checkingDotInZones(v, dot1, strCmd);
			for(int x=0; x<1000; x++);
			checkingDotInZones(v, dot2, strCmd);
			break;
		case 2:
			directionChecking(dot1, dot2, strCmd);
			break;
		case 3:
			dotInBorderChecking(v, dot1, strCmd);
			for(int x=0; x<1000; x++);
			dotInBorderChecking(v, dot2, strCmd);
			break;
		case 4:
			dotCCheckingOnAB(dot1, dot2, strCmd);
			break;
	}
}
