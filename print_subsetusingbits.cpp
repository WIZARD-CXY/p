#include<cstdio>
using namespace std;
void print_subset(int n,int s){
  for(int i = 0; i < n;  i++)
    if(s&(1<<i)) printf("%d ",i+1);
  printf("\n");
}
int main(){
  for (int i =0 ; i< (1<<10); i++)
    print_subset(10,i);
}
