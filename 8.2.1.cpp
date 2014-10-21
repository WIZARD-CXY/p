/*************************************************************************
	> File Name: 8.2.1.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 20 Oct 2014 07:59:00 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void merge_sort(int *A, int x, int y, int *T){
    if(y-x >1 ){
        int m = (x+y)/2;
        int p=x, q=m, i=x;

        merge_sort(A,x,m,T);
        merge_sort(A,m,y,T);        
        
        while(p<m || q<y){
            
            if(q >= y || (p<m && A[p]<=A[q])) T[i++] = A[p++];
            else T[i++] = A[q++];
        }
        for(i=x; i<y; i++) A[i]=T[i];
    }
}

int main(){
    int A[10]={2,1,9,4,6,3,5,8,0,7};
    int T[10];

    merge_sort(A,0,2,T);
    
    for(int i=0; i<10; i++){
        cout<<A[i]<<" ";
    }
}
