/*************************************************************************
	> File Name: subset.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年12月05日 星期四 21时55分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void print_subset(int n,int* A,int cur){
    for(int i =0; i < cur; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    int s = cur ? A[cur-1]+1 : 0;

    for(int i = s; i < n;i++){
        A[cur] = i;
        print_subset(n,A,cur+1);
    }
}
void print_subset2(int n,int* B,int cur){
    //recursive end
    if(cur == n){ 
        for(int i=0; i<cur; i++){
            if(B[i] == 1){
                printf("%d ",i);
            }
        }
    printf("\n");
    return;
    }
    B[cur] = 1 ;
    print_subset2(n,B,cur+1);
    B[cur] = 0;
    print_subset2(n,B,cur+1);

}
int A[1000];
int B[1000];
int main(){
    memset(B,0,sizeof(B));
    print_subset2(3,B,0);
    //print_subset(3,A,0);
}
