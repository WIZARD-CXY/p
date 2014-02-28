#define MAXN 1001
#include <cstring>
int d[MAXN][MAXN];
int a[MAXN][MAXN];

int n;

int max(int a, int b){
   if(a>b){
       return a;
   } else {
       return b;
   }
}
int dp(int i, int j){
    if(d[i][j]>=0) return d[i][j];
    return d[i][j]=a[i][j]+(i==n?0:max(dp(i+1,j),dp(i+1,j+1)));
}

int main(){

	memset(d,-1,sizeof(d));
}
