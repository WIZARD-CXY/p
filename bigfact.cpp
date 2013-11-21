/*************************************************************************
	> File Name: bigfact.c
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月21日 星期四 19时49分07秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

const int maxn=3000;
int result[maxn];

int main(){
    int i,j,n;
    scanf("%d",&n);

    memset(result,0,maxn);

    result[0]=1;

    for(i=2;i<=n;i++){
        int c=0;
        int s;
        for(j=0;j<maxn;j++){
            s = result[j]*i+c;
            result[j] = s%10;
            c = s/10; 
        }

    }

    for(j=maxn-1;j>=0;j--) 
         if(result[j]) 
           break;
    
    for(i=j;i>=0;i--){
        printf("%d",result[i]);
    }
    printf("\n");
}
