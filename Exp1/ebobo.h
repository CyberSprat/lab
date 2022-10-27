#ifndef EBOBO_H
#define EBOBO_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	float zoneAX[360], zoneAY[360];
	float zoneBX[270], zoneBY[270];
	float zoneCX[90], zoneCY[90];
	float zoneDX[360], zoneDY[360];
} circle;

#define PI 3.141593

void coordZoneA(float *circleCoordsX, float *circleCoordsY){
	for(int i=0; i<360; i++){
		circleCoordsX[i]=0+1*cos((i+1)*PI/180);
		circleCoordsY[i]=0+1*sin((i+1)*PI/180);
	}
}

void coordZoneB(float *circleCoordsX, float *circleCoordsY){
	for(int i=0; i<270; i++){
		if(i<90){
			circleCoordsX[i]=0+3*cos((i+1)*PI/180);
			circleCoordsY[i]=0+3*sin((i+1)*PI/180);
		}
		else if(i>=90 && i<270){
			circleCoordsX[i]=0+3*cos((i+91)*PI/180);
			circleCoordsY[i]=0+3*sin((i+91)*PI/180);
		}
	}
}

void coordZoneC(float *circleCoordsX, float *circleCoordsY){
	for(int i=0; i<90; i++){
		circleCoordsX[i]=0+3*cos((i+91)*PI/180);
		circleCoordsY[i]=0+3*sin((i+91)*PI/180);
	}
}

void coordZoneD(float *circleCoordsX, float *circleCoordsY){
	for(int i=0; i<360; i++){
		circleCoordsX[i]=0+3*cos((i+1)*PI/180);
		circleCoordsY[i]=0+3*sin((i+1)*PI/180);
	}
}

void checkingDotInZones(circle v, float *dot, char *cmdStr){
	system(cmdStr);
	for(int i=0; i<360; i++){
		if(i<90){
			if((dot[0]>=0 && dot[1]>=0) && (dot[0]<=v.zoneAX[i] && dot[1]<=v.zoneAY[i])){
				printf("Dot x=%f y=%f seached in zone A\n", dot[0], dot[1]);
				break;
			}
		}

		else if(i>=90 && i<180){
			if((dot[0]<=0 && dot[1]>=0) && (dot[0]>=v.zoneAX[i] && dot[1]<=v.zoneAY[i])){
				printf("Dot x=%f y=%f seached in zone A\n", dot[0], dot[1]);
				break;
			}
		}

		else if(i>=180 && i<270){
			if((dot[0]<=0 && dot[1]<=0) && (dot[0]>=v.zoneAX[i] && dot[1]>=v.zoneAY[i])){
				printf("Dot x=%f y=%f seached in zone A\n", dot[0], dot[1]);
				break;
			}
		}

		else if(i>=270){
			if((dot[0]>=0 && dot[1]<=0) && (dot[0]<=v.zoneAX[i] && dot[1]>=v.zoneAY[i])){
				printf("Dot x=%f y=%f seached in zone A\n", dot[0], dot[1]);
				break;
			}
		}
	}

	for(int i=0; i<360; i++){
		if(i<90){
			if((dot[0]>=v.zoneAX[i] && dot[1]>=v.zoneAY[i]) && (dot[0]<=v.zoneBX[i] && dot[1]<=v.zoneBY[i])){
				printf("Dot x=%f y=%f seached in zone B\n", dot[0], dot[1]);
				break;
			}
		}

		else if(i>=90 && i<180){
			continue;
		}

		else if(i>=180 && i<270){
			if((dot[0]<=v.zoneAX[i] && dot[1]<=v.zoneAY[i]) && (dot[0]>=v.zoneBX[i-91] && dot[1]>=v.zoneBY[i-91])){
				printf("Dot x=%f y=%f seached in zone B\n", dot[0], dot[1]);
				break;
			}
		}

		else if(i>=270){
			if((dot[0]>=v.zoneAX[i] && dot[1]<=v.zoneAY[i]) && (dot[0]<=v.zoneBX[i-91] && dot[1]>=v.zoneBY[i-91])){
				printf("Dot x=%f y=%f seached in zone B\n", dot[0], dot[1]);
				break;
			}
		}
	}

	for(int i=0;i<90; i++){
		if((dot[0]<=v.zoneAX[i+90] && dot[1]>=v.zoneAY[i+90]) && (dot[0]>=v.zoneCX[i] && dot[1]<=v.zoneCY[i])){
				printf("Dot x=%f y=%f seached in zone C\n", dot[0], dot[1]);
				break;
			}
	}

	for(int i=0; i<360; i++){
		if(i<90){
			if(dot[0]>v.zoneDX[i] && dot[1]>v.zoneDY[i]){
				printf("Dot x=%f y=%f seached in zone D\n", dot[0], dot[1]);
				break;
			}
		}
		else if(i>=90 && i<180){
			if(dot[0]<v.zoneDX[i] && dot[1]>v.zoneDY[i]){
				printf("Dot x=%f y=%f seached in zone D\n", dot[0], dot[1]);
				break;
			}
		}

		else if(i>=180 && i<270){
			if(dot[0]<v.zoneDX[i] && dot[1]<v.zoneDY[i]){
				printf("Dot x=%f y=%f seached in zone D\n", dot[0], dot[1]);
				break;
			}
		}
		else if(i>=270){
			if(dot[0]>v.zoneDX[i] && dot[1]<v.zoneDY[i]){
				printf("Dot x=%f y=%f seached in zone D\n", dot[0], dot[1]);
				break;
			}
		}
	}
}

void diretionChecking(float *dot1, float *dot2, char *cmdStr){
	system(cmdStr);
	if((dot1[0]==dot2[0]) && (dot1[1]!=dot2[1]))
		printf("AB is horisontal\n");
	else if((dot1[0]!=dot2[0]) && (dot1[1]==dot2[1]))
		printf("AB is vertical\n");
}

void dotInBorderChecking(circle v, float *dot, char *cmdStr){
	system(cmdStr);
	for(int i=0; i<360; i++){
		if(i<90 &&(v.zoneAX[i]==dot[0] && v.zoneAY[i]==dot[1]))
			printf("Dot x=%f y=%f on the border between zone A and zone B\n", dot[0], dot[1]);
		else if((i>=90 && i<180) && (v.zoneAX[i]==dot[0] && v.zoneAY[i]==dot[1]))
			printf("Dot x=%f y=%f on the border between zone A and zone C\n", dot[0], dot[1]);
		else if(i>=180 &&(v.zoneAX[i]==dot[0] && v.zoneAY[i]==dot[1]))
			printf("Dot x=%f y=%f on the border between zone A and zone B\n", dot[0], dot[1]);
		}
	for(int i=0; i<270; i++)
		if(v.zoneBX[i]==dot[0] && v.zoneBY[i]==dot[1])
			printf("Dot x=%f y=%f on the border between zone B and zone D\n", dot[0], dot[1]);
	for(int i=0; i<90; i++)
		if(v.zoneCX[i]==dot[0] && v.zoneCY[i]==dot[1])
			printf("Dot x=%f y=%f on the border between zone C and zone D\n", dot[0], dot[1]);
}

void dotCCheckingOnAB(float *dot1, float *dot2, char *cmdStr){
	system(cmdStr);
	float c[2]={0, 0};
	printf("Enter x and y dot C:");
	scanf("%f%f", &c[0], &c[1]);
	if((c[0]>=dot1[0] && c[1]>=dot1[1]) && (c[0]<=dot2[0] && c[1]<=dot2[1]))
		printf("Dot C in AB\n");
	else
		printf("Dot C out AB\n");
}

void printMenuSelected_checkingDotInZones(char *cmdStr){
	system(cmdStr);
	printf(">Checking dots in zones\n");
	printf("Line direction\n");
	printf("Checking dots in zone's border\n");
	printf("Checking dot C in line\n");
}

void printMenuSelected_directionChecking(char *cmdStr){
	system(cmdStr);
	printf("Checking dots in zones\n");
	printf(">Line direction\n");
	printf("Checking dots in zone's border\n");
	printf("Checking dot C in line\n");
}

void printMenuSelected_dotInBorderChecking(char *cmdStr){
	system(cmdStr);
	printf("Checking dots in zones\n");
	printf("Line direction\n");
	printf(">Checking dots in zone's border\n");
	printf("Checking dot C in line\n");
}

void printMenuSelected_dotCCheckingOnAB(char *cmdStr){
	system(cmdStr);
	printf("Checking dots in zones\n");
	printf("Line direction\n");
	printf("Checking dots in zone's border\n");
	printf(">Checking dot C in line\n");
}
#endif /*EBOBO_H*/