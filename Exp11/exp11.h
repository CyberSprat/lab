#ifndef EXP11_H
#define EXP11_H

#include <stdio.h>
#include <stdlib.h>

void enAlphGen(char (*mas)[26]){
    int LETTER=65, letter=97;
    for(int i=0; i<26; i++){
        mas[0][i]=letter+i;
        mas[1][i]=LETTER+i;
    }
}

void enPanChecking(char *text, char (*enAlph)[26]){
    int panCheck=0;
    for(int i=0; i<26; i++){
        for(int j=0; text[j]!='\n' && text[j]!='\0'; j++){
            if(enAlph[0][i]==text[j] || enAlph[1][i]==text[j]){
                panCheck++;
                break;
            }
        }
    }
    if(panCheck==26)
        printf("This is pangram\n");
    else
        printf("This isn\'t pangram\n");
}

#endif // EXP11_H
