#ifndef EXP13_H
#define EXP13_H

#include <iostream>

void bubbleSort(int *mas, unsigned int size){
	for(int i=0; i<size; i++)
		for(int j=0; j<size-1; j++)
			if(mas[j]>mas[j+1])
				std::swap(mas[j],mas[j+1]);
}

void selectSort(int *mas, unsigned int size){
		for(int i=0; i<size; i++){
			int temp=size-1;
			for(int j=i;  j<size; j++)
				if(mas[j]<mas[temp])
					temp=j;
			std::swap(mas[i], mas[temp]);
		}
	}

#endif //EXP13_H