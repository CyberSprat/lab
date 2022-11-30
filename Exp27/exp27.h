#ifndef EXP27_H
#define EXP27_H

#include <iostream>
#include <regex>

void enemyScaner(std::string *text, int deviceCount){
	std::regex hackCheck("[\\w\\s.]*n[\\w\\s.]*e[\\w\\s.]*t[\\w\\s.]*w[\\w\\s.]*o[\\w\\s.]*r[\\w\\s.]*k[\\w\\s.]*");
	for(int i=0; i<deviceCount; i++)
		if(regex_match(text[i], hackCheck))
			std::cout << i << "\n";
}

void strIf(std::string *text, int deviceCount){
	int i=0;
	while(i<deviceCount){
		std::cout << "Enter " << i << " device:\n";
		 getline(std::cin, text[i]);
		if(text[i].size()-1>=5 && text[i].size()-1<=100)
			i++;
	}
}

#endif // EXP27_H
