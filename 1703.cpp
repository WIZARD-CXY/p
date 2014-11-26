/*************************************************************************
	> File Name: 1703.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 25 Nov 2014 10:06:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX 10000*2+16
#include<cstdio>

int p[MAX];
int rank[MAX];

void make_set(int n){
    for(int i=0; i<n; i++){
        p[i]=i;
        rank[i]=0;
    }
}

int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}

void unite(int x,int y){
    int rx=find(x);
    int ry=find(y);

    if(rx==ry){
        return;
    }

    if(rank[rx]>rank[ry]){
        p[ry]=rx;
    }else{
        p[rx]=ry;
        if(rank[x]==rank[y]){
            rank[y]++;
        }
    }
}

bool same(int x,int y){
    return find(x) == find(y);
}

int main(){
    freopen("1703.txt","r",stdin);

    int t;
    cin>>t;

    while(t--){
        int n,m;

        cin>>n>>m;

        getchar();

        make_set(2*n);

        while(m--){
            char message;
            int x,y;
            scanf("%c%d%d%*c",&message,&x,&y);

            if(message=='A'){
                if(same(x,y)){
                    cout<<"In the same gang."<<endl;
                }else if(same(x,y+n)){
                    cout<<"In different gangs."<<endl;
                }else{
                    cout<<"Not sure yet."<<endl;
                }
            }
            else{
                unite(x,y+n);
                unite(x+n,y);

            }
        }
    }
    
}
