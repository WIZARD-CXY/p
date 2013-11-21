/*************************************************************************
	> File Name: cycle.c
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月21日 星期四 19时14分50秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(){
    char word[100];
    scanf("%s",word);

    int len = strlen(word);
    
    for(int i=1; i<len; i++)
        if(len%i==0){

            int ok = 1;
            for(int j=i; j<len; j++){
                if(word[j] != word[j%i]){
                    ok=0;
                    break;
                }
                if(ok){
                    printf("%d\n",i);
                    break;
                } 
        }
    }
}
