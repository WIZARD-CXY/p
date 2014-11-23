/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Nov 2014 02:08:05 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>

struct node{
    int val;
    node *left;
    node *right;
};

node* buildTree(){
    string input;

    cin>>input;

    if(input=="Push"){
        int val;
        cin>>val;
        node* newnode=new node();
        newnode->val=val;
        newnode->left=buildTree();
        newnode->right=buildTree();
        return newnode;
    }
    return NULL;
}
bool first =1;

void postOrder(node *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        
        if(first){
            cout<<root->val;
            first=0;
            
        }else{
            cout<<" "<<root->val;
        }
    }
}
int main(){
    freopen("3.txt","r",stdin);


    int n;
    cin>>n;

    node* root=buildTree();
    postOrder(root);

}
