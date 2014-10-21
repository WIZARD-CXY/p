/*************************************************************************
	> File Name: 6.3.3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Sep 2014 10:07:08 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void build(int n, char *s1, char *s2 ,char *s)
{
    if(n <= 0) return;

    int p = strchr(s2,s1[0])-s2;
    build(p, s1+1, s2, s);
    build(n-p-1,s1+p+1,s2+p+1,s+p);
    s[n-1] = s1[0];
}
#define MAXN 100
int main()
{
    char s1[MAXN];
    char s2[MAXN];
    char ans[MAXN];

    while(scanf("%s%s", s1, s2) == 2)
    {
        int n = strlen(s1);
        build(n,s1,s2,ans);
        ans[n]='\0';
        printf("%s\n",ans);
    }
}
