/*************************************************************************
	> File Name: 6.3.2.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Sep 2014 07:56:40 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<queue>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 50

vector<int> res;

struct Node{
    int have_value;
    int v;
    Node *left,*right;
};

Node *root;
int failed = 0;

Node *newnode()
{
    Node* u = (Node*)malloc(sizeof(Node));
    if(u!=NULL)
    {
        u->have_value = 0;
        u->left = u->right = NULL;
    }

    return u;
}
void addnode(int v, char *s)
{
    int n = strlen(s);
    Node *u = root;

    for(int i=0; i<n; i++)
    {
        if(s[i]=='L')
        {
            if(u->left == NULL ) u->left = newnode();
            u=u->left;
        }
        else if(s[i]=='R')
        {
            if(u->right == NULL) u->right=newnode();
            u = u->right;
        }
    }
    if(u->have_value){
      failed =1;
        return;
    }
    u->v=v;
    u->have_value=1;
}


char s[MAXN+10];
int read_input()
{
    root = newnode();
    for(;;)
    {
        if(scanf("%s",s) != 1) return 0;

        if(!strcmp(s,"()")) break;

        int v;
        sscanf(&s[1], "%d", &v);
        addnode(v,strchr(s, ',')+1);
        
        if(failed == 1 ) {
            failed=0;
            return -1;
        }
    }
    
    return 1;
}


int bfs()
{
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node *node = q.front();
        if(node->have_value ==0 ) return -1;
        
        res.push_back(node->v);

        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
        q.pop();
    }

}
void remove_tree(Node *root)
{
    if (root == NULL) return;
    remove_tree(root->left);
    remove_tree(root->right);
    free(root);
}

int main(){
   
    freopen("6.3.2.txt","r",stdin);
    for(;;)
    {
        int result= read_input();
        if(result==-1 ) {
            cout<<-1<<endl; 
            continue;
        }
        if(result == 0)
           break;
        if(result !=-2) 
        {
            if( bfs() != -1){
               for(unsigned int i =0; i!= res.size(); i++)
                cout<<res[i]<<" ";
               cout<<endl;
            }else {
                cout<<-1<<endl;
            }
            
        }
        remove_tree(root);
    }
}
