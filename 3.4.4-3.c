/*************************************************************************
	> File Name: 3.4.4-3.c
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月19日 星期二 21时16分11秒
 ************************************************************************/

#include<stdio.h>
int main(){
    char s[100];
    int i = 0;

    while((s[i]=getchar()) && s[i] != '\n'){
        i++;
    }

    s[i] ='\0';
    printf("%s\n",s);
    return 0;
}
