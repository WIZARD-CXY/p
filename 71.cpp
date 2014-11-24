/*************************************************************************
	> File Name: 71.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Nov 2014 10:00:18 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<map>

bool isAlphanum(char c){
    if((c>='a' && c<='z') || (c>= 'A' && c<='Z') || ( c>='0' && c<= '9' )){
        return true;
    }else {
        return false;
    }
}

void process(string &s){
    for(int i=0; i<s.size(); i++){
        if( s[i]>='A' && s[i] <= 'Z' ){
            s[i]=s[i]-'A'+'a';
        }
    }
}


int main(){
    freopen("71.txt","r",stdin);
    string s;
    getline(cin,s);
    int i=0;

    while(!isAlphanum(s[i])) {
        i++;// ignore leading non alphanum;
    }
    int p1=i,p2=i;
    map<string, int> mm;

    while(p2<s.size()){

        while(isAlphanum(s[p2]) && p2<s.size()){
            p2++;
        }

        string word=s.substr(p1,p2-p1);
        process(word);
        if(mm.find(word)==mm.end()){
            mm[word]=1;
        }else{
            mm[word]++;
        }

        while(!isAlphanum(s[p2]) && p2<s.size()){
            p2++;
        }
        p1=p2;
        
    }

    int max=-1;
    string maxword;

    for(map<string,int>::iterator it=mm.begin(); it!=mm.end(); it++){
        if(it->second > max){
            max=it->second;
            maxword=it->first;
        }
    }
    cout<<maxword<<" "<<max<<endl;
}
