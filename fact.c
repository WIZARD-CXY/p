/*************************************************************************
	> File Name: fact.c
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月20日 星期三 22时04分20秒
 ************************************************************************/

#include<stdio.h>
int f(int n){
    return (n==0)?1:f(n-1)*n;
}

int main(){
    printf("%d\n",f(10000000));
}
