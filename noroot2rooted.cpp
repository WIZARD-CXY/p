/*************************************************************************
	> File Name: noroot2rooted.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 02 Nov 2014 08:43:10 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
const int maxn=30;
int p[maxn];

vector<int> G[maxn];
int n;
void read_tree(){
    int u,v;

    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);

    }
}

void dfs(int u,int fa){
    int d=G[u].size();

    for(int i=0; i<d; i++){
        int v=G[u][i];

        if(v!=fa){
            dfs(v, p[v]=u);
        }
    }
}
int main(){
    freopen("rootedtree.txt","r",stdin);
    read_tree();
    int root=3;

    p[root]=-1;
    dfs(root,-1);
    for(int i=0; i<n; i++){
        cout<<p[i]<<" ";
    }
}
