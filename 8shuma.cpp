/*************************************************************************
	> File Name: 8shuma.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年12月12日 星期四 21时27分31秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

set<int> vis;

typedef int State[9];
const int MAXSTATE = 1000000;
State st[MAXSTATE],goal;
int dist[MAXSTATE];
int fa[MAXSTATE];
int last_dir[MAXSTATE];
int lastZ[MAXSTATE];

int try_to_insert(int s)
{
    int v=0;
    for(int i=0;i<9;i++){
        v=v*10+st[s][i];
    }
    if(vis.count(v)) return 0;

    vis.insert(v);
    return 1;
}

void init_lookup_table(){ 
    vis.clear();
    try_to_insert(1);//first is already visited   
}
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};

int bfs()
{
    init_lookup_table();
    int front=1,rear=2;

    while(front<rear){
        State& s =st[front];
        if(memcmp(goal,s,sizeof(s)) ==0 ) return front;

        int z;//index indicate 0 position
        for(z=0;z<9;z++) if(!s[z]) break;

        int x=z/3,y=z%3;

        for(int d=0;d<4;d++){
            int newx=x+dx[d];
            int newy=y+dy[d];
            int newz=newx*3+newy;

            if(newx >=0 && newx <3 && newy>=0 && newy<3){
                State &t = st[rear];
                memcpy(&t,&s,sizeof(s)); // this will be the new node
                t[newz]=s[z];
                t[z]=s[newz];
                
                dist[rear] = dist[front] +1;
                if(try_to_insert(rear)){
                    last_dir[rear]=d;   
                    fa[rear] = front;
                    lastZ[rear]=z;
                    rear++;
                } 
            }

        }
        front++;

    }
    return 0;
}
void print_path(int front){

    if(fa[front]!=0){
        print_path(fa[front]);
    
        printf("move %dth element to direction %d\n",lastZ[front],last_dir[front]);
    } 
}

int main(){
    for(int i=0;i<9;i++) scanf("%d",&st[1][i]);//initial State
    for(int i=0;i<9;i++) scanf("%d",&goal[i]);//goal State

    int ans =bfs();
    if(ans>0) print_path(ans);
    else printf("-1\n");

    return 0;
}
