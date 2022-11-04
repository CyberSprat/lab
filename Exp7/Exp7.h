#ifndef EXP7_H
#define EXP7_H

#include <iostream>

bool PalindromChecking(std::string text){
    int value=0;
    std::string reversedText=text;
    for(int i=0; text[i]!='\0'; i++)
        value++;
    for(int i=0; text[i]!='\0'; i++)
       reversedText[i]=text[--value];
    if(text==reversedText)
        return true;
    else
        return false;
}

#endif // EXP7_H
