/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Nov 2014 01:20:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>

int main(){
    freopen("2.txt","r",stdin);

    int n,p;
    cin>>n>>p;

    long long a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);

    int i;
    int maxlength=0;
    for(i=0; i<n; i++){
        int length= upper_bound(a,a+n,p*a[i])-a-i;
        if(length==n+1){
            
        } else if(maxlength<length){
            maxlength=length;
        }
    }
    cout<<maxlength<<endl;

}
