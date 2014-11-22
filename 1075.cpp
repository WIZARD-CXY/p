/*************************************************************************
	> File Name: 1075.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 21 Nov 2014 11:08:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<set>
#include<algorithm>

int main(){
    int n;
    cin>>n;
    set<int> iset;

    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        iset.insert(temp);
    }
    cout<<iset.size()<<endl;

    for(set<int>::iterator it=iset.begin(); it!=iset.end(); it++){
        cout<<*it<<" ";
        
    }
}
