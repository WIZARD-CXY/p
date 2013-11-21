/*************************************************************************
	> File Name: 3.4.4-4.c
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月19日 星期二 21时20分16秒
 ************************************************************************/

#include<stdio.h>
char* mystrchr(char* s,char c){
    while(*s && *s != c){
        s++;
    }

    if(*s == c) return s;
    else return NULL;
}
