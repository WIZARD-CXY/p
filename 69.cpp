/****************
 * *********************************************************
	> File Name: 69.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Nov 2014 07:39:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<sstream>
#include<algorithm>

string int2string(int n){
    stringstream ss;
    if(n>=0 && n<10){
        ss<<"000"<<n;
        return ss.str();
    } else if( n<100 ){
        ss<<"00"<<n;
        return ss.str();
    } else if( n <1000 ){
        ss<<"0"<<n;
        return ss.str();
        
    }else {
        ss<<n;
        return ss.str();
    }
}

int main(){
    freopen("69.txt","r",stdin);

    int n;

    cin>>n;
    string s = int2string(n);

    bool flag=true;

    for(int i=0; i<s.size()-1; i++){
        if(s[i]!=s[i+1]){
            flag=false;
            break;
        }
        
    }

    if(flag){
        cout<<s<<" - "<<s<<" = 0000"<<endl;
        return 0;
    }

    do{
        sort(s.begin(),s.end());

        string smalls = s;

        for(int i=0; i<s.size()/2; i++){
            char temp;
            temp=s[i];
            s[i]=s[s.size()-1-i];
            s[s.size()-1-i]=temp;
            
        }

        int big,small;
        stringstream bigSS,smallSS;
        bigSS<<s;
        smallSS<<smalls;

        bigSS>>big;
        smallSS>>small;
        
        int num=big-small;

        s=int2string(num);
        
        printf("%04d - %04d = %04d\n",big, small,num);

    }while(s!="6174");

    return 0;
}
