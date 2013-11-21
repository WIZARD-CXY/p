/*************************************************************************
	> File Name: swap.c
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月20日 星期三 21时11分49秒
 ************************************************************************/

#include<stdio.h>
int* swap(int *a,int *b){
    int c=12;
    int *t=0;
    a=b;
    b=t;
    return &c;
}
void f(){
    int a,b;
}
int main(){
    int a=3,b=4;
    int *c=swap(&a,&b);
    f();
    printf("*c is %d",*c);
    printf("%d %d\n",a,b);
    return 0;
}
