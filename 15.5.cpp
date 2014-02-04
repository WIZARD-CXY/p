/*************************************************************************
	> File Name: 15.5.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Fri 24 Jan 2014 10:13:19 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define N 5
double e[N+2][N+2];//expectation
double w[N+2][N+2];//prob
int root[N+2][N+2];//record the root node pos of sub-tree

void Optimal_Bst(double *p, double *q, int n)
{
    int i, j, r, l;

    double t;

    for(i=1; i<=n+1; i++)
    {
        e[i][i-1]=q[i-1];
        w[i][i-1]=q[i-1];
    }


    for(l = 1; l<=n; l++)
    {
        for(i=1; i<=n-l+1; i++)
        {
            j=i+l-1;
            e[i][j]=0x7fffffff;

            w[i][j]=w[i][j-1]+p[j]+q[j];

            for(r=i; r<=j; r++)
            {
                t=e[i][r-1]+e[r+1][j]+w[i][j];

                if(t-e[i][j]<-1e-10)
                {
                    e[i][j]=t;
                    root[i][j]=r;
                }
            }
        }
    }
}

void PrintE()
{
    int i,j;
    for(i=1; i <= N+1; i++)
    {
        for(j=0; j <= N; j++)
        {
            if(e[i][j])
                 cout<<e[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

void PrintW()
{
    int i,j;
    for(i=1; i <= N+1; i++)
    {
        for(j=0; j <= N; j++)
            if(w[i][j])
                cout<<w[i][j]<<' ';

        cout<<endl;
    }
    cout<<endl;
}

void PrintRoot()
{
    int i,j;
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++){
            cout<<root[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

void Construct_Optimal_Best(int start,int end)
{
    int r = root[start][end];

    if ( r-1 < start){
        cout<<'d'<<r-1<<" is k"<<r<<"'s left child"<<endl;
    } else {
        cout<<'k'<<root[start][r-1]<<" is k"<<r<<"'s left child"<<endl;
        Construct_Optimal_Best(start,r-1);
    }

    if(end<r+1){
        cout<<"d"<<end<<" is k"<<r<<"'s right child"<<endl;
    } else {
        cout<<'k'<<root[r+1][end]<<" is k"<<r<<"'s right child"<<endl;

        Construct_Optimal_Best(r+1,end);
    }
}


int main()
{
    int n=N;

    double p[N+1]={0,0.15,0.1,0.05,0.1,0.2};
    double q[N+1]={0.05,0.1,0.05,0.05,0.05,0.1};


    Optimal_Bst(p,q,n);

    PrintE();
    PrintW();
    PrintRoot();
    cout<<"============================"<<endl;
    cout<<'k'<<root[1][N]<<" is root"<<endl;
    Construct_Optimal_Best(1,N);

    return 0;
}



