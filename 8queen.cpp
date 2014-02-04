#include<cstdio>
using namespace std;
int vis[3][100];
int C[10];
int n=8;
int tot=0;
void search(int cur){
  if(cur == n){
    tot++;
    for(int i=0; i<n; i++){
      printf("%d ",C[i]);
    }
    printf("\n");
  }
  else for(int i=0; i< n; i++){
    if(!vis[0][i] && !vis[1][cur-i+n] && !vis[2][cur+i]){
      vis[0][i]=vis[1][cur-i+n]=vis[2][cur+i]=1;
      C[cur]=i;
      search(cur+1);
      vis[0][i]=vis[1][cur-i+n]=vis[2][cur+i]=0;
    }
  }
}




int main(){
  search(0);
  printf("%d\n",tot);
}
