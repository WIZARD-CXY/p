/*************************************************************************
	> File Name: dijkstra.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Sun 02 Feb 2014 03:12:48 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=100;

// n #node
// v source node
// dist[] the distance from the ith node to the source node
// prev[] the previous node of the i-th node
// w[][] every two nodes distance aka weight

int dist[maxn];
int pre[maxn];
int w[maxn][maxn];
int n,line;

void dij(int n, int v){
    
    bool s[maxn];
    
    for(int i=1; i<=n; i++){
        dist[i]=w[v][i];
        s[i]=0;
        if(dist[i] == 0x7fffffff){
            pre[i]=0;
        }else{
            pre[i]=v;
        }
    }

    dist[v]=0;
    s[v]=1;

    for (int i=2; i<=n; i++){
        int temp = 0x7fffffff;
        int u=v;

        for(int j=1; j<=n; j++)
            if((!s[j]) && dist[j]<temp){
                u=j;
                temp=dist[j];
            }

        s[u]=1;

        for(int j=1; j<=n; j++){
            if((!s[j]) && w[u][j] < 0x7fffffff){
                int newdist = dist[u] + w[u][j];
                if(newdist < dist[j]){
                    dist[j]=newdist;
                    pre[j]=u;
                }
            }
        }
    }
}


void searchPath(int *prev, int v, int u){

    int que[maxn];
    int tot=1;

    que[tot]=u;
    tot++;

    int tmp = prev[u];

    while(tmp!=v){
        que[tot]=tmp;
        tot++;
        tmp=prev[tmp];
    }
    que[tot]=v;
    for(int i=tot; i>=1; i--){
        if(i!=1 ) cout<<que[i]<<"->";
        else cout<<que[i]<<endl;
    }
}

int main(){

    freopen("inputdijkstra.txt","r",stdin);

    cin>>n;
    cin>>line;

    int p,q,len;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            w[i][j]=0x7fffffff;
        }
    }

    for(int i=1; i<=line; i++){
        cin>>p>>q>>len;
        if(len<w[p][q]){
            w[p][q]=len;
            w[q][p]=len;
        }
    }

    for(int i=1; i<=n; i++){
        dist[i]=0x7fffffff;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%8d\t",w[i][j]);
        }
        printf("\n");
    }

    dij(n,1);

    cout<<"the length from src node to the last node: "<<dist[n]<<endl;

    cout<<"path is : ";
    searchPath(pre,1,n);
}
