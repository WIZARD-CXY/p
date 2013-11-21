/*************************************************************************
	> File Name: 3.4.4-2.c
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月19日 星期二 20时54分20秒
 ************************************************************************/
#include<string.h>
#include<stdio.h>
int main(){
    int i;
    char s[100];

    int num=0;
    fgets(s,sizeof(s),stdin);

    for(i = 0; i < strlen(s)-1; i++){
        num = num*10+s[i]-'0';
    }
    printf("%d\n",num);

}
