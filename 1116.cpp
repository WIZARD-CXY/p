/*************************************************************************
	> File Name: 1116.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Nov 2014 06:59:42 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#define NMAX 8

int mm[NMAX][NMAX];
int n;
int count;
int history[NMAX];

void dfs(int i){
    if(i==n){
		count++;
		
		for(int i=0; i<n; i++){
		    cout<<history[i]<<" ";
		}
		
		cout<<endl;
		return;
    }

    for (int c=1; c<5; c++){
		int ok=1;

		for(int j=0; j<i; j++){
		    if(mm[i][j] && c==history[j]){
		        ok=0;
		    }
		}
		if(ok){
		    history[i]=c;
		    dfs(i+1);
		}
    }
}

int main(){
    freopen("1116.txt","r",stdin);

    cin>>n;

    for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
		    cin>>mm[i][j];
		}
    }

    dfs(0);

    cout<<count<<endl;
}
