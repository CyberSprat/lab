#include "ebobo.h"

int main(){
	circle v7;
	float tempDot1[2]={1,1};
	float tempDot2[2]={3,3};
	coordZoneA(v7.zoneAX, v7.zoneAY);
	coordZoneB(v7.zoneBX, v7.zoneBY);
	coordZoneC(v7.zoneCX, v7.zoneCY);
	coordZoneD(v7.zoneDX, v7.zoneDY);
	dotCCheckingOnAB(tempDot1, tempDot2, "clear");
	return 0;
}