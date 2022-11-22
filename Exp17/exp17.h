#ifndef EXP17_H
#define EXP17_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>
#include <ctime>

void withRegexFunc(std::string *text, unsigned int strCount){
    std::regex site("http://[\\w]+\\.[\\w]{2,5}");
    std::regex email("[\\w]+@[\\w]+\\.[\\w]{2,5}");
    for(int i=0; i<strCount; i++)
        if(std::regex_match(text[i], site) || std::regex_match(text[i], email))
            for(int j=0; j<text[i].size(); j++)
                text[i][j]='*';
}

void withoutRegexFunc(std::string *text, unsigned int strCount){
    for(int i=0; i<strCount; i++)
        if((text[i][0]=='h' && text[i][1]=='t' && text[i][2]=='t' && text[i][3]=='p' && text[i][4]==':' && text[i][5]=='/' && text[i][6]=='/'))
            for(int j=0; j<text[i].size(); j++)
                text[i][j]='*';
    for(int i=0; i<strCount; i++)
        for(int j=0; j<text[i].size(); j++)
            if(text[i][j]=='@')
                for(int k=0; k<text[i].size(); k++)
                text[i][k]='*';
}
#endif // EXP17_H
