/*****************************************************************************************************************************************************
*	Проект:Задание 17
*	Автор:Борисов Владислав И-428
******************************************************************************************************************************************************/

#include "exp17.h"

using namespace std;

int main(){
    unsigned int strCount=0;
    cout << "Enter string\'s count:";
    cin >> strCount;
    string text[strCount], text_copy[strCount];
    for(int i=0; i<strCount; i++){
        cout << "Enter " << i+1 <<" " << "string:\n";
        cin >> text[i];
    }
    for(int i=0; i<strCount; i++)
       text_copy[i]=text[i];
    clock_t withRegexTime0=clock();
    withRegexFunc(text, strCount);
    clock_t withRegexTime1=clock();
    double withRegexTime=(withRegexTime1-withRegexTime0)/CLOCKS_PER_SEC;
    clock_t withoutRegexTime0=clock();
    withoutRegexFunc(text_copy, strCount);
    clock_t withoutRegexTime1=clock();
    double withoutRegexTime=(withoutRegexTime1-withoutRegexTime0)/CLOCKS_PER_SEC;
    cout << "With regex:" << endl;
    for(int i=0; i<strCount; i++)
        cout << text[i] << endl;
    cout << "Without regex:" << endl;
    for(int i=0; i<strCount; i++)
        cout << text_copy[i] << endl;
    printf("Time with regex:%.1lf\n", withRegexTime);
    printf("Time without regex:%.1lf\n", withoutRegexTime);
    return 0;
}
