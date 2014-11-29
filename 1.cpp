/*************************************************************************
		> File Name: 1.cpp
		> Author: 
		> Mail: 
		> Created Time: Sun 23 Nov 2014 01:01:02 PM CST
	 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<algorithm>


char process(char a){
    if(a>='a' && a<='z'){
		return a-'a'+'A';
    }else {
	// for digit and already capitalized char
	    return a;
    }
}
int main(){
    freopen("1.txt","r",stdin);
    string s1,s2;
    cin>>s1>>s2;
    vector<char> res;

    int i,j;
    for(i=0,j=0; j<s2.size(); ){
		if(s1[i]==s2[j]){
		    i++;
		    j++;
		}else{
		    if(find(res.begin(),res.end(),process(s1[i])) == res.end()){
		        res.push_back(process(s1[i]));
		    }
		    i++;
		}
    }

    if(s1.size()-i>0){
		for(;i<s1.size();i++){
		    if(find(res.begin(),res.end(),process(s1[i])) == res.end()){
		        res.push_back(process(s1[i]));
		    }
		    
		}
    }
    
    for(int i=0; i<res.size(); i++){
	    cout<<res[i];
    }
    cout<<endl;

}
