/*************************************************************************
	> File Name: buildtree.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Nov 2014 12:21:42 PM CST
 ************************************************************************/
#include<cstdio>
#include<iostream>
using namespace std;

struct node{
    int val;
    node *left;
    node *right;
};

void build(node *&root, int v){
    if(root==NULL){
        root = new node;
        root->val=v;
        root->left=NULL;
        root->right=NULL;
        return;
    }
    if(v<root->val){
        build(root->left,v);
    }else {
        build(root->right,v);
    }
}
void preoder(node *root){
    if(root){
        cout<<root->val<<endl;
        preoder(root->left);
        preoder(root->right);
    }
}
int main(){
    freopen("test.txt","r",stdin);
    int n;
    cin>>n;
    node *root=NULL;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        build(root,temp);
    }

    preoder(root);
}
