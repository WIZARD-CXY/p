/*************************************************************************
	> File Name: BT.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月24日 星期日 15时22分31秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAXN 100

char s[MAXN +20];

int read_input(){
    failed =0;
    root = newnode();

    while(1){
        if(!(cin>>s)) return 0;

        if(!strcmp("()")) break;

        int v;
        sscanf(&s[1],"%d",v);
        addnode(v,strchr(s,',')+1);
    }

    return 1;
}

struct Node{
    int have_value;
    int v;
    struct Tnode *left,*right;
};

Node *root;

Node* newnode(){
    Node *u = new Node();

    if(u!=NULL){
        u->have_value =0;
        u->left = u->right = NULL;
    }

    return u;
}

void addnode(int v,char *s){
    int n =strlen(s);
    Node* u = root;
    for(int i =0; i<n; i++)
    if(s[i] == 'L'){
        if(u->left == NULL) u->left = newnode();

        u=u->left;
    } else if(s[i] == 'R'){
        if(u->right == NULL) u->right = newnode();
        u=u->right;
    }

    if(u->have_value) failed =1;
    u->v =v;
    u->have_value = 1;

}
int n=0;
int ans[MAXN];
int bfs(){
    int front = 0,rear =1;

    Node* q[MAXN];
    q[0] =root;
    while(front < rear){
        Node* u = q[front++];

        if(!u->have_value ) return 0;

        ans[n++] = u->v;

        if(u->left != NULL) q[rear++] = u->left;
        if(u->right != NULL) q[rear++] = u->right;
    }

    return 1;
}

void remove_tree(Node* u){
    if( u == NULL) return;

    remove(u->left);
    remove(u->right);
    delete u;
}
int main(){
    
}
