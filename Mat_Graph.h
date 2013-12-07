/*************************************************************************
	> File Name: Mat_Graph.h
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年12月05日 星期四 22时44分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
#include<queue>
#include<cstring>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

queue<int> Q;

class Mat_Graph{
public:
    int n;
    int color[N+1];
    int d[N+1];
    int parent[N+1];
    int Map[N+1][N+1];

    Mat_Graph(int num):n(num){
        memset(Map,0,sizeof(Map));
    }
    void AddDoubleEdge(int a,int b,int value = 1){
        addSingleEdge(a,b,value);
        addSingleEdge(b,a,value);
    }

    void addSingleEdge(int a,int b,int value =1){
        Map[a][b] = value;
    }

    void deleteDoubleEdge(int a,int b){
        deleteSingleEdge(a,b);
        deleteSingleEdge(b,a);
    }
    void  deleteSingleEdge(int a,int b){
        Map[a][b]=0;
    }

    void BFS(int s);
    void Print_Path(int s,int v);
};

void Mat_Graph::BFS(int s){
    int u,v;
    // initial all node 
    for(u=1; u<=n; u++){
        color[u] =WHITE;
        d[u] = 0x7fffffff;
        parent[u]=0;
    }

    color[s]=GRAY;
    d[s]=0;
    parent[s]=0;

    Q.push(s);
    while(!Q.empty()){
        u = Q.front();Q.pop();
        for(v=1;v<=n;v++){
            if(Map[u][v]==1){
            if(color[v] == WHITE){
                color[v] = GRAY;
                d[v]=d[u]+1;
                parent[v]=u;
                Q.push(v);
            }

            }}
        color[u]=BLACK;
    }
}
// recursive print_path
void Mat_Graph::Print_Path(int s,int v){

    BFS(s);
    if(v==s){
        cout<<s<<" ";
    }else {
        if( parent[v] == 0 ){
           cout<<"No path from "<<s<<" to "<<v<<" exists"<<endl;
    } else{
        Print_Path(s,parent[v]);
        cout<<v<<" ";
    }

}}
