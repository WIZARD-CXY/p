/*************************************************************************
	> File Name: Link_Graph.h
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年12月07日 星期六 16时57分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

queue<int> Q;
struct Vertex;
struct Edge{
    int start;
    int end;
    int value;
    Edge *next;
    Edge(int s,int e,int v):start(s),end(e),value(v),next(NULL){}
};
struct Vertex{
    int color;
    int d;
    int parent;
    Edge *head;
    Vertex():head(NULL),color(WHITE),d(0x7fffffff),parent(0){}
};
class Link_Graph{
public:
    int n;
    Vertex *V;
    Link_Graph(int num):n(num){
        V = new Vertex[n+1];
    }
}
