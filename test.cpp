/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 02 Nov 2014 07:12:24 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    vector<int> a(10,0);

    a[1]=10;
    cout<<a[1];
    cout<<5/2<<" "<<-5/2<<endl;
    double aa=0.03450;

    printf("%.2E\n",aa);

    int data1[] = { 1, 2, 5, 6, 8, 9, 10  }; 
    int data2[] = { 0, 2, 3, 4, 7, 8, 10  }; 
     
    vector<int> v1(data1, data1+sizeof(data1)/sizeof(data1[0]));
    vector<int> v2(data2, data2+sizeof(data2)/sizeof(data2[0])); 
     
    vector<int> tmp(v1.size()+v2.size()); 

    vector<int> res = vector<int> (tmp.begin(), set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),tmp.begin()));


    cout<<"haha"<<endl;
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<endl;
    }
}
