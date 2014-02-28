#include <iostream>
using namespace std;

int bs(int *a,int x,int y,int v){
    while(x<=y){
       int m=(x+y)/2;
       if(a[m]==v) return m;
       else if(a[m]>v) y=m-1;
       else x=m+1;
    } 
    return -1;
}

int main(){

    int a[10]={1,2,3,4,5,6,7,8,9,10};

    int v;
    cin>>v;
    cout<<bs(a,0,10,v)<<endl;
}
    
