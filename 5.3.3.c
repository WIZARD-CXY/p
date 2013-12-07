/*************************************************************************
	> File Name: 5.3.3.c
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月22日 星期五 21时11分04秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;

    int i=1;
    while(sum < n){
        sum+=i;
        i++;
    }

    printf("%d/%d\n",i-1-sum+n,sum-n+1);
}
