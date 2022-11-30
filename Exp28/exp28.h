#ifndef EXP28_H
#define EXP28_H

#include <iostream>
#include <clocale>
#include <algorithm>
#include <iterator>
#include <Windows.h>

void ruAlphGen(char (*mas)[32]){
	int LETTER=192, letter=224;
	for(int i=0; i<32; i++){
		mas[0][i]=letter+i;
		mas[1][i]=LETTER+i;
	}
}

void letterDelGame(std::string text, char (*ruAlph)[32]){
	std::string inGame=text+" запретил букву ", inGame_copy;
	for(int i=0; i<32; i++){
		std::cout << inGame << ruAlph[0][i] << "\n";
		remove_copy(inGame.begin(), inGame.end(), back_inserter(inGame_copy), ruAlph[0][i]);
		inGame="";
		inGame=inGame_copy;
		inGame_copy="";
	}
}

#endif // EXP28_H
