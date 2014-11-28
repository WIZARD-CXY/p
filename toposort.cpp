#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define MAXN 10000

int c[MAXN];
int topo[MAXN],t;
int n;
int G[MAXN][MAXN];

bool dfs(int u){
   c[u]=-1;

   for(int v=0; v<n; v++){
      if(G[u][v]){
        if(c[v]<0) return 0;//exist cycle
        else if(!c[v] && !dfs(v)) return 0;

      }
   } 
   c[u]=1;
   topo[--t]=u;
   return 1;
   
}

bool toposort(){
   t=n;
   memset(c,0,sizeof(c));
   for(int u=0; u<n; u++){
      if(!c[u]){
         if(!dfs(u)){
            return false;
         }
      }
   }
   return true;
}
int main(){
    n=4;
    G[0][1]=1;
    G[1][2]=1;
    G[0][3]=1;
    cout<<toposort()<<endl;

    for(int i=0; i<n; i++){
        cout<<topo[i]<<endl;
    }
}
    
