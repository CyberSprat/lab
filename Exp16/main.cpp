/*****************************************************************************************************************************************************
*	Проект:Задание 16
*	Автор:Борисов Владислав И-428
******************************************************************************************************************************************************/

#include "exp16.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
	char enAlph[2][26];
	enAlphGen(enAlph);
	string text;
	cout << "Enter the text:";
	getline(cin, text);
	text=spaceDel(text);
	text=customReg(text, enAlph);
	cout << text << endl;
	return 0;
}
