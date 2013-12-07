/*************************************************************************
	> File Name: print_permutation.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年12月05日 星期四 20时47分21秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void print_permutation(int n,int* A,int cur)
{
    int i,j;

    if(cur == n){
        for(i=0; i<n; i++){
            printf("%d ",A[i]);
        }
        printf("\n");
    }
    else {
        for(i=1; i<=n; i++){
            int ok =1;
            for(j=0; j<cur; j++){
                if(A[j] == i) ok=0;
            }
            if(ok){
                    A[cur]=i;
                    print_permutation(n,A,cur+1);
                }
            }
        }
    }
int A[1000];
int main(){
    memset(A,0,sizeof(A)); 
    print_permutation(5,A,0);
}
