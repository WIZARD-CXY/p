/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Nov 2014 02:39:55 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<map>

int happiness[201];
int cost[201][201];
int pre[201];
int dis[201];
bool vis[201];
int routenum[201]; //routenum[i] indicate how many routes from src to i-th city
int precitynum[201];
int hap[201];
map<string,int> name2int;
map<int,string> int2name;

void dijk(int n){
    for(int i=0; i<n; i++){
        dis[i]=cost[i][0];
    }

    for(int i=0; i<n; i++){
        int minIdx=-1;
        int min=0x7fffffff;

        for(int j=0; j<n; j++){
            if(!vis[j] && dis[j]<min){
                min=dis[j];
                minIdx=j;
            }
        }
        if(minIdx==-1) break;

        vis[minIdx]=1;

        //relaxation
        for(int j=0; j<n; j++){
            if(!vis[j] && cost[minIdx][j] < 0x7fffffff){
                if((dis[minIdx]+cost[minIdx][j]) < dis[j]){
                    pre[j]=minIdx;
                    precitynum[j]=precitynum[minIdx]+1;
                    routenum[j]=routenum[minIdx];
                    dis[j]=dis[minIdx]+cost[minIdx][j];
                    hap[j]=hap[minIdx]+happiness[j];

                }else if(dis[minIdx]+cost[minIdx][j] == dis[j]){
                    routenum[j]+=routenum[minIdx];
                    
                    if(hap[j] < hap[minIdx]+happiness[j]){
                        hap[j] = hap[minIdx]+happiness[j];
                        pre[j] = minIdx;
                        precitynum[j] = precitynum[minIdx]+1;
                    } else if(hap[j] == hap[minIdx]+happiness[j]){
                        if(precitynum[j] > precitynum[minIdx]+1){
                            precitynum[j] = precitynum[minIdx]+1;
                            pre[j]=minIdx;
                        }
                    }
                }
            }
        }

    }
    
}
void printPath(int src, int dest){
    if(pre[dest]!=src){
        printPath(src,pre[dest]);
    }
    cout<<"->"<<int2name[dest];
    
}
int main(){
    freopen("4.txt","r",stdin);
    int n,k;
    cin>>n>>k;

    string s;

    cin>>s;
    name2int[s]=0;
    int2name[0]=s;

    for(int i=1; i<n; i++){
        string city;
        int happ;
        cin>>city>>happ;
        name2int[city]=i;
        int2name[i]=city;
        happiness[i]=happ;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j){
                cost[i][j]=cost[j][i]=0x7fffffff;
            }
        }
        pre[i]=-1;
    }

    for(int i=0; i<k; i++){
        string city1,city2;
        int co;
        cin>>city1>>city2>>co;
        cost[name2int[city1]][name2int[city2]]=co;
        cost[name2int[city2]][name2int[city1]]=co;
    }
    precitynum[0]=0;
    routenum[0]=1;

    dijk(n);
    
    int romnum=name2int["ROM"];
    cout<<routenum[romnum]<<" "<<dis[romnum]<<" "<<hap[romnum];
    cout<<" "<<hap[name2int["ROM"]]/precitynum[name2int["ROM"]]<<endl;
    cout<<int2name[0];
    printPath(0,name2int["ROM"]);
   
    cout<<endl;
    return 0;
}
