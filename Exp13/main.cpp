#include "exp13.h"
#include <cstdlib>
#include <ctime>

using namespace std;
int main(int argc, char *argv[])
{
	srand(time(0));
	int mas1[10], mas2[10];
	for(int i=0; i<10; i++){
		mas1[i]=1+rand()%10;
		mas2[i]=1+rand()%10;
	}
	cout << "Before sort:" <<endl;
	for (int i = 0; i < 10; i++)
	cout << mas1[i] << " ";
	cout << endl;
	for (int i = 0; i < 10; i++)
	cout << mas2[i] << " ";
	cout <<endl << "After Bubble sort:" << endl;
	bubbleSort(mas1, 10);
	for (int i = 0; i < 10; i++)
	cout << mas1[i] << " ";
	cout <<endl << "After Selection sort:" << endl;
	selectSort(mas2, 10);
	for (int i = 0; i < 10; i++)
	cout << mas2[i] << " ";
	return 0;
}