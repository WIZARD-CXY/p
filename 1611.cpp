/*************************************************************************
	> File Name: 1611.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 25 Nov 2014 12:58:52 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>

int num[30001]; //record the x root's set size
int p[30001];
int rank[30001];

int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}

void merge(int x, int y){
    int rx=find(x);
    int ry=find(y);

    if(rx==ry){
        return;
    }
    
    if(rank[rx]>rank[ry]){
        p[ry]=rx;
        num[rx]+=num[ry];
    }else{
        p[rx]=ry;
        if(rank[x]==rank[y]){
            rank[y]++;
        }

        num[ry]+=num[rx];
    }
}

int main(){
    int n,m;
   
    freopen("1611.txt","r",stdin);
    while(cin>>n>>m){
        if(m==n && n==0){
            break;
        }
        if(m==0){
            cout<<1<<endl;
            return 0;
        }
        for(int i=0; i<n; i++){
            p[i]=i;
            num[i]=1;
        }

        for(int i=0; i<m; i++){
            int k;
            int x;
            cin>>k>>x;

            for(int j=1; j<k; j++){
                int y;
                cin>>y;
                merge(x,y);
            }
            
        }

        int sum=0;

        for(int i=0;i<n; i++){
            if(find(i)==find(0)){
                sum++;
            }
        }
        cout<<sum<<endl;

        //cout<<num[find(0)]<<endl;
    }
}
