/*************************************************************************
	> File Name: binaryset.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Nov 2014 11:38:58 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
using namespace std;
#include<cstdio>

void print_subset(int *S ,int n){
    int i,j;

    for(int i=1; i<(1<<n); i++){
        for(j=0; j<n; j++){
            if(i & (1<<j)) printf("%d",S[j]);
        }

        printf("\n");
        
    }
}
int main(){
    int n,i;

    while(scanf("%d",&n)>0){
        int *S =(int*)malloc(n*sizeof(int));

        for(int i=0; i<n; i++){
            scanf("%d",&S[i]);
        }

        print_subset(S,n);
    }
}
