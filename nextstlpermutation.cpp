/*************************************************************************
	> File Name: nextstlpermutation.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年12月05日 星期四 21时20分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int n,p[10];
    scanf("%d",&n);
    
    for(int i=0; i<n; i++){
        scanf("%d",&p[i]);
    }
    sort(p,p+n);
    int num = 0;
    do{
        for(int i=0; i<n; i++){
            printf("%d ",p[i]);
        }
        num++;
        printf("\n");
    }while(next_permutation(p,p+n));
    printf("the permutation num is %d",num);
}
