/*************************************************************************
	> File Name: 1501.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Nov 2014 10:13:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int w[16];
int l[16];
int r[16];

int dfs(int level, int node){

    w[level]++;
    
    if(l[node]==0 && r[node]==0) return 1;

    int lheight;
    int rheight;

    if(l[node]){
        lheight=dfs(level+1,l[node]);
    }
    if(r[node]){
        rheight=dfs(level+1,r[node]);
    }

    return (lheight>rheight?lheight:rheight)+1;
}
int main(){
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>l[i]>>r[i];
    }

    int height=dfs(1,1);

    int wmax=0;

    for(int i=1; i<=height; i++){
        if(wmax<w[i]){
            wmax=w[i];
        }
    }

    cout<<wmax<<" "<<height<<endl;
}
