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

void build(int n,char* pre,char* in,char* post){
    if(n>0){
        int p=strchr(in,pre[0])-in;
        build(p,pre+1,in,post);
        build(n-p-1,pre+p+1,in+p+1,post+p);
        post[--n]=pre[0];
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
