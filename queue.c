/*************************************************************************
	> File Name: queue.c
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月24日 星期日 10时36分43秒
 ************************************************************************/

#include<stdio.h>
#define MAXN 50

int queue[MAXN];

int main()
{
    int n,front,rear;

    scanf("%d",&n);

    for(int i=0; i<n; i++){
        queue[i] = i+1;
    }

    front=0;
    rear=n;

    while(front<rear){
        printf("%d ",queue[(front++)%n]);
        queue[(rear++)%n] = queue[(front++)%n];
    }

    return 0;
}
