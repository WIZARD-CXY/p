/*************************************************************************
	> File Name: 6.4.1.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月25日 星期一 10时30分03秒
 ************************************************************************/
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
#define MAXN 100
int mat[MAXN][MAXN],visited[MAXN][MAXN];

void dfs(int x,int y){
    if( !visited[x][y] && mat[x][y] ){
        visited[x][y] = 1;
        dfs(x-1,y-1);dfs(x-1,y);dfs(x-1,y+1);
        dfs(x,y-1);dfs(x,y+1);
        dfs(x+1,y-1);dfs(x+1,y);dfs(x+1,y+1);
    }
}

int main(){
    memset(mat,0,sizeof(mat));
    memset(visited,0,sizeof(visited));

    int n;

    scanf("%d",&n);
    char s[50];
    int count = 0;
    
    for(int i=0; i<n; i++){
        scanf("%s",s);

        for(int j=0; j<n; j++){
            mat[i+1][j+1] = s[j]-'0';
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(mat[i][j] && !visited[i][j]){
                count++;
                dfs(i,j);
            }
        }
    }
    printf("%d\n",count);
}
