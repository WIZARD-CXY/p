/*************************************************************************
	> File Name: map.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Nov 2014 10:46:26 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<algorithm>

int main(){
    map<string,int> M;

    M["SRM"]=10;
    M["Top"]=1;
    M["Coder"]=2;

    M["Code"]=100;

    int x=M["Top"]+M["Coder"];

    for(map<string,int>::iterator it=M.begin(); it!=M.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    set<string> S;

    S.insert("Top");
    S.insert("Coder");
    S.insert("Haha");

    for(set<string>::iterator it=S.begin(); it!=S.end(); it++){
        cout<<*it<<endl;
    }

    cout<<min(10,199)<<endl;
    cout<<max(1000,199)<<endl;


    int aa=100;
    int bb=100000;

    swap(aa,bb);

    cout<<aa<<" swaped "<<bb<<endl;
}
