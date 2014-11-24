/*************************************************************************
	> File Name: 1070.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Nov 2014 09:00:19 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>
#include<vector>

struct mooncake{
    double amount;
    double price;
};

bool cmp(const mooncake &a, const mooncake &b){
    return a.price/a.amount - b.price/b.amount > 1e-9;
}
int main(){
    freopen("70.txt","r",stdin);
    int n;
    double d;
    cin>>n>>d;

    vector<mooncake> res(n);


    for(int i=0; i<n; i++){
        cin>>res[i].amount;
    }

    for(int i=0; i<n; i++){
        cin>>res[i].price;
    }
    sort(res.begin(),res.end(),cmp);

    double profit=0.0;
    int i=0;
    while(d>0 && i<n){

        int temp;
        if(d>res[i].amount){
            profit+=res[i].price;
            temp=res[i].amount;

        } else {
            profit+=d*res[i].price/res[i].amount;
            temp=d;
        }
        i++;
        d-=temp;
    }
    
    printf("%.2lf\n",profit);

}
