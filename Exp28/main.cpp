/*****************************************************************************************************************************************************
*	������:������� 28
*	�����:������� ��������� �-428
******************************************************************************************************************************************************/

#include "exp28.h"

using std::cout;
using std::cin;

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char ruAlph[2][32];
	ruAlphGen(ruAlph);
	std::string text;
	cin >> text;
	letterDelGame(text, ruAlph);
    return 0;
}
