/*************************************************************************
	> File Name: 1501.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Nov 2014 10:13:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int l[16];
int r[16];

void preorder(int node){
    cout<<node<<" ";

    if(l[node]){
        preorder(l[node]);

    }
    if(r[node]){
        preorder(r[node]);
    }
}
void inorder(int node){

    if(l[node]){
        inorder(l[node]);
    }
    cout<<node<<" ";
    if(r[node]){
        inorder(r[node]);
    }
}
void postorder(int node){
    if(l[node]){
        postorder(l[node]);

    }
    if(r[node]){
        postorder(r[node]);
    }
    cout<<node<<" ";

}

int main(){
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>l[i]>>r[i];
    }

    preorder(1);
    cout<<endl;
    inorder(1);
    cout<<endl;
    postorder(1);
    cout<<endl;
}
