/*************************************************************************
	> File Name: 3.4.4-1.c
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月19日 星期二 20时47分01秒
 ************************************************************************/

#include<stdio.h>
int main(){
    int a[100],i=0,num=0;

    char c;
    while((c=getchar())!=EOF){
        putchar(c);
    }

    while((a[i]=getchar()) && a[i] != '\n'){
        num = num*10+a[i]-'0';
        i++;
    }
    printf("%d\n",num);
    return 0;
}
