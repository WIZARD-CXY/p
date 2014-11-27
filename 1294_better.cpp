//use back tracking and another array u to reduce time cost
#include<cstdio>
int l[11],n;
bool u[11];
void dfs(const int& i)
{
    if(i>n)
    {
        for(int j=1;j<=n;++j)
        printf("%d ",l[j]);
        printf("\n");
        return; 

    } 
    for(int j=1;j<=n;++j)
    if(!u[j])
    {
        l[i]=j; 
        u[j]=1;
        dfs(i+1);
        u[j]=0;

    }

}   
int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;

}
