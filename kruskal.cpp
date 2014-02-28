/*************************************************************************
	> File Name: kruskal.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Mon 27 Jan 2014 12:13:43 PM CST
 ************************************************************************/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Road{
    int c1,c2;//vertex to connect
    int value;//weight
};

int no;
int line;
Road road[100];
int node[101];

bool myCmp(const Road &a,const Road &b)
{
    if(a.value < b.value)
        return 1;

    return 0;
}

int Find_Set(int n){
    return node[n]==n?n:Find_Set(node[n]);
}

bool Merge(int s1, int s2){
    int r1 = Find_Set(s1);
    int r2 = Find_Set(s2);
    if( r1 == r2){
        return 0;
    }
    if(r1 <r2){
        node[r2] = r1;
    } else {
        node[r1] = r2;
    }

    return 1;
}

int main(){
    freopen("input.txt","r",stdin);


    cout<<"input the number of node"<<endl;
    cin>>no;
    cout<<"input the number of line"<<endl;
    cin>>line;
    cout<<"Input the edge"<<endl;


     for(int i=0; i<no; i++){
        node[i]=i;
     }

    for(int i =0; i<line; i++){
        cin>>road[i].c1>>road[i].c2>>road[i].value;
    }
    sort(road,road+line,myCmp);

    //for(int i=0; i<line ; i++){
    //    cout<<road[i].value<<endl;
    //}

    int sum=0,count=0;

    for(int i=0; i<line; i++){
        if(Merge(road[i].c1,road[i].c2)){
            count++;
            sum+=road[i].value;
        }
        if(count==no-1){
            break;
        }
    }
    cout<<sum<<endl;
}
