/*************************************************************************
	> File Name: movball.c
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月24日 星期日 12时04分19秒
 ************************************************************************/

#include<cstdio>
#include<iostream>
using namespace std;
struct Node {
    Node *left,*right;
    int val;
}; 

void link(Node* a, Node* b){
    a->right = b;
    b->left = a;

}
Node* findNode(Node *head,int val){
    Node *p = head->right;
    while( p->val != val && p != NULL){
        p=p->right;
    }

    return p;
    
}
int main(){
    int n;
    scanf("%d",&n);

    Node* head = new Node();
    Node* pre;
    int first=1;
    for(int i=0; i<n; i++){
        Node* item = new Node();
        item->val = i+1;
        if(first){
            first = 0;
            link(head,item);
        }else{
            link(pre,item);
        }

        pre = item;

    }
    
    Node* ptr = head->right;
    while(ptr != NULL){
        printf("%d ",ptr->val);
        ptr=ptr->right;
    }
    printf("\n");

    string type;
    int X,Y;
   
    cin>>type>>X>>Y;

    Node* x= findNode(head,X);
    Node* y =findNode(head,Y);

    link(x->left,x->right);

    if(type[0] == 'A'){
        link(y->left,x);
        link(x,y);
    } else {
        link(x,y->right);
        link(y,x);
    }
    
    ptr = head->right;
    while(ptr != NULL){
        printf("%d ",ptr->val);
        ptr=ptr->right;
    }
}
