/*****************************************************************************************************************************************************
*   Проект:Задание 7
*   Автор:Борисов Владислав И-428
******************************************************************************************************************************************************/
#include "Exp7.h"

using namespace std;

int main(){
    string text;
    cout << "Enter the text(without big letters):";
    cin >> text;
    cout << PalindromChecking(text) <<endl;

    return 0;
}