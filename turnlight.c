#include<stdio.h>
#include<string.h>
#define MAXN 1000+10
int a[MAXN];

int main(){
  int i,j,k,n;

  memset(a,0,sizeof(a));

  scanf("%d%d",&n,&k);

  for (i=0; i<k; i++){
    for (j=0; j<n;j++){
      if((j+1)%(i+1) ==0 ) a[j] = !a[j];
    }
  }

  int first = 1;
  for(i=0;i<n;i++){
    if(a[i]){
      if(first == 1){
        first = 0;
      } else{
        printf(" ");
      }
      printf("%d",i+1);
    }
  }
  printf("\n");
}
