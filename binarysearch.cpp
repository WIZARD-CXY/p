#include <iostream>
using namespace std;


int bs(int *A, int l, int r, int v){
        while(l<r){
                int mid=(l+r)/2;
                if(A[mid]==v){
                        return mid;
                } else if(A[mid]>v){
                        r=mid;
                } else {
                        l=mid+1;
                }
        }
        return -1;
}
int main(){
        int A[10]={1,2,3,4,5,6,7,8,9,10};

        cout<<bs(A,0,10,1)<<endl;// search from index 0
}

