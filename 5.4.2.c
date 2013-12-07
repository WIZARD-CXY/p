#include<stdio.h>
#include<string.h>

//for n which is not too big
int is_prime(int n){
  for(int i = 2; i*i <=n;i++){
    if (n%i == 0)
      return 0;
  }
  return 1;
}

int prime[100],count = 0;
int main(){
  int n,p[100];

  // construct a prime table
  for(int i = 2;i <= 100; i++){
    if(is_prime(i))
      prime[count++] = i;
  }

  while(scanf("%d",&n) == 1){
    printf("%d! =",n);
    memset(p,0,sizeof(p));


    for(int i = 2; i<=n ;i++){
      int m = i;

      for(int j = 0; j < count;j ++)
        while( m % prime[j] == 0)
        {
          m/=prime[j];
          p[j]++;
        }

    }

    for (int i = 0; i <= count; i++)
      if(p[i] != 0)
        printf(" %d",p[i]);
      else 
        break;
    printf("\n");
  }
}




