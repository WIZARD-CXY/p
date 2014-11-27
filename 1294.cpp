/*************************************************************************
	> File Name: 1294.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Nov 2014 12:45:56 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n;
int a[15];
#include<cstdio>

void dfs(int i){
    if(i==n+1){

        for(int j=1; j<=n; j++){
            cout<<a[j]<<" ";
        }
        cout<<endl;
        return;

    }

    for(int k=1; k<=n; k++){
        int ok=1;

        // if k is already take from pre number,then ok =0 change another k
        for(int j=1; j<i; j++){
            if(a[j]==k){
                ok=0;
            }
        }

        if(ok){
            a[i]=k;
            dfs(i+1);
        }
    }
}


int main(){

    cin>>n;

    dfs(1);
}
