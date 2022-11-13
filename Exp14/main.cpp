/*****************************************************************************************************************************************************
*	Проект:Задание 14
*	Автор:Борисов Владислав И-428
******************************************************************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void mixInMas(int *mas, unsigned int weight){
    swap(mas[0], mas[weight-1]);
    for(int i=1; i<weight-1; i++)
        swap(mas[i], mas[i+1]);
}

int main(){
    srand(time(0));
    unsigned int n=0;
    cout << "Enter size of array:";
    cin >> n;
    int mas[n];
    for(int i=0; i<n; i++)
        mas[i]=rand();
    cout << "Before mix:" << endl;
    for(int i=0; i<n; i++)
        cout << mas[i] << " ";
    cout << endl;
    mixInMas(mas, n);
    cout << "After mix:" << endl;
    for(int i=0; i<n; i++)
        cout << mas[i] << " ";
    return 0;
}
