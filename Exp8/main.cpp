/*****************************************************************************************************************************************************
*	Проект:Задание 8
*	Автор:Борисов Владислав И-428
******************************************************************************************************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	unsigned int n=0, k=0;
	cout << "Enter n:";
	cin >> n;
	string masStr[n];
	cout << "Enter k:";
	cin >> k;
	string masQuery[k];
	for(int i=0; i<n; i++){
		system("cls");
		cout << "Enter " << i+1 << " string:";
		cin >> masStr[i];
	}
	
	for(int i=0; i<k; i++){
		system("cls");
		cout << "Enter " << i+1 << " search query:";
		cin >> masQuery[i];
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			if(masStr[i]==masQuery[j])
				cout << masStr[i] << endl;
		}
	}
	
	return 0;
}