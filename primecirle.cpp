/*************************************************************************
	> File Name: primecirle.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年12月07日 星期六 20时26分14秒
 ************************************************************************/
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int is_prime(int n){
    if(n==0 || n==1 ){
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int isp[1000];
int A[100];
int vis[100];

void dfs(int cur,int n){
    if(cur == n && isp[ A[0] + A[n-1] ]){
        for(int i=0; i < n;i++){
            printf("%d ",A[i]);

        }
        printf("\n");
    }
    else for (int i=2;i<=n;i++){
        if( !vis[i] && isp[ i + A[cur-1] ]){
            A[cur]=i;
            vis[i]=1;
            dfs(cur+1,n);

            vis[i]=0;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 2; i< n*2; i++) isp[i]=is_prime(i);

    for(int i = 0; i<n; i++) A[i]=i+1; // generate the 1st permutation

    // A[0] being 1 is very important
    dfs(1,n);

    printf("old methd is below\n");
    do{
        int ok=1;
        for(int i=0;i<n;i++){
            if (!isp[A[i]+A[(i+1)%n]]){
                ok=0;
                break;
            }
        }
        if(ok){
            for(int i=0; i<n;i++){
                printf("%d ",A[i]);
            }
            printf("\n");
        }
    }while(next_permutation(A+1,A+n));
    
}
