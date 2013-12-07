/*************************************************************************
	> File Name: stlqueue.c
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月24日 星期日 10时46分56秒
 ************************************************************************/

#include<stdio.h>
#include<queue>
using namespace std;


queue<int> q;
int main(){
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        q.push(i+1);
    }

    while(!q.empty()){
        printf("%d ",q.front());
        q.pop();
        q.push(q.front());
        q.pop();
    }
    return 0;
}
