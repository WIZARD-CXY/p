/*************************************************************************
	> File Name: reconstructTree2.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Nov 2014 11:59:59 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>

struct node{
    char val;
    node *left;
    node *right;

};

void rebuild(int n, const char* pre, const char *in,node* &root){
    if(n>0){
        root = new node;
        root->val=pre[0];
        root->left=NULL;
        root->right=NULL;

        int p = strchr(in,pre[0])-in;
        rebuild(p,pre+1,in,root->left);
        rebuild(n-p-1,pre+p+1,in+p+1,root->right);
    }

}

void post(node *root){
    if(root){
        post(root->left);
        post(root->right);
        printf("%c",root->val);
    }
}
int main(){

    char pre[10];
    char in[10];

    node *root=NULL;

    scanf("%s%s",pre,in);

    int n=strlen(pre);

    rebuild(n,pre,in,root);

    post(root);
    
}
