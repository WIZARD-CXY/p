/*************************************************************************
	> File Name: 1083.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Nov 2014 10:28:12 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include <cmath>

int main(){
    int n;

    cin>>n;

    int i=(int)floor((sqrt(1+8.0*n)-1)/2-(1e-9))+1;
    int s=(i+1)*i/2;

    if(i%2==0){
        cout<<i-s+n<<"/"<<s-n+1<<endl;
    }else{
        cout<<s-n+1<<"/"<<i-s+n<<endl;
    }
}
