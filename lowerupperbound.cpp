/*************************************************************************
	> File Name: lowerupperbound.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Nov 2014 12:28:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>

int v[10000];

int main(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);

    for(int i=0; i<n; i++){
        scanf("%d",&v[i]);
    }
    sort(v,v+n);

    for(int i=0; i<m; i++){
        scanf("%d%d",&a,&b);
        printf("%d %d \n",*upper_bound(v,v+n,b), *lower_bound(v,v+n,a));
    }
}
