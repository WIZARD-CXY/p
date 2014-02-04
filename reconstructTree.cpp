/*************************************************************************
	> File Name: reconstructTree.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月24日 星期日 16时47分20秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ans[1000];

void build(int n,char* s1,char* s2,char*s){
    if(n>0){
        int p = strchr(s2,s1[0])-s2;
        build(p,s1+1,s2,s); // recursive call in left sub-tree
        build(n-p-1,s1+p+1,s2+p+1,s+p);//recusive call in right sub-tree
        printf("%c",s1[0]);//print root node
    }
}

int main(){
    char s1[100];
    char s2[100];
    
    while(scanf("%s%s",s1,s2))
    {
        int n = strlen(s1);
        build(n,s1,s2,ans);
        ans[n]='\0';
        printf("%s\n",ans);
    }
}
