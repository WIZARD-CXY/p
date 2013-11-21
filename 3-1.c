/*************************************************************************
	> File Name: 3-1.c
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月19日 星期二 23时11分46秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(){
    int score,scores[101];
    memset(scores,0,sizeof(scores));

    while(scanf("%d",&score)==1){
        scores[score]++;
    }

    int i,max=0;
    for(i=0;i<101;i++){
        if(scores[i] >= max){
            max=scores[i];
        }
    }
    
    int first=1;
    for(i=0; i<101;i++){
        if(scores[i] == max){
            if(first==1){
                first = 0;
            } else {
                printf(" ");
            }
            printf("%d",i);
        }
    }   
    printf("\n");
}
