/*************************************************************************
	> File Name: 1160.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Nov 2014 11:26:44 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 101
int a[maxn][maxn];

//reference http://blog.csdn.net/summercpp/article/details/39940485
int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	int tot=0;
	int x,y,i,r,k,sum;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	a[x=n/2][y=n/2]=1;
	tot=2;
	for(k=1;k<=n/2;k++){
		y++;
		for(r=1;r<=2*k;r++){
			a[x][y]=tot;
			tot++;
			x--;
		}
		x++;
		y--;
		for(r=1;r<=2*k;r++){
			a[x][y]=tot;
			tot++;
			y--;
		}
		y++;
		x++;
		for(r=1;r<=2*k;r++){
			a[x][y]=tot;
			tot++;
			x++;
		}
		x--;
		y++;
		for(r=1;r<=2*k;r++){
			a[x][y]=tot;
			tot++;
			y++;
		}
		y--;
		
	}
	for(x=0;x<n;x++){
		for(y=0;y<n;y++){
			if (y!=n-1)
			{
				printf("%d ",a[x][y]);	
			}else
			{
				printf("%d",a[x][y]);	
			}
			
		}
		printf("\n");
	} 
	sum=0;
	for (i = 0; i < n; ++i)
	{
		sum+=a[i][i];
	}
	for (i = 0; i < n; ++i)
	{
		sum+=a[i][n-i-1];
	}
	printf("%d\n",sum-a[(n-1)/2][(n-1)/2] ); 
	return 0;
}
