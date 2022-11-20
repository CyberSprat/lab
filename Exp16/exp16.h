#ifndef EXP16_H
#define EXP16_H

#include <iostream>
#include <string>
#include <cstdlib>

void enAlphGen(char (*mas)[26]){
	int LETTER=65, letter=97;
	for(int i=0; i<26; i++){
		mas[0][i]=letter+i;
		mas[1][i]=LETTER+i;
	}
}

std::string spaceDel(std::string text){
    for(; text[0]==' ';)
        text.erase(text.begin());

	for(int i=0; i<text.size(); i++)
		if(text[i]==' ')
			while(text[i+1]==' ')
				text.erase(text.begin()+(i+1));
    return text;
}

std::string customReg(std::string text, char (*alph)[26]){
    for(int i=0; i<26; i++)
		if(text[0]==alph[0][i])
			text[0]=alph[1][i];
	for(int i=1; i<text.size(); i++)
		for(int j=0; j<26; j++)
			if(text[i]==alph[1][j])
				text[i]=alph[0][j];
    return text;
}
#endif //EXP16_H
