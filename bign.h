/*************************************************************************
	> File Name: bign.h
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月21日 星期四 20时51分49秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1000;

struct bign{
    int len, s[maxn];
    
    bign(){ memset(s,0,maxn); len=1; }

    bign operator = (const char* num){
        len = strlen(num);
        for(int i = 0; i < len; i++){
            s[i]=num[len-1-i]-'0';
        }
        return *this;
    }

    bign operator = (int num){
        char s[maxn];
        sprintf(s,"%d",num);
        len = strlen(num);
        *this = s;
        return *this;
    }

    bign(int num) { *this = num; }
    bign(char* num) { *this =  num; }

    string str() const{
        string res = "";
        for(int i=0;i<len;i++){
            res = char(res+'0')+res;
        }
        if(res == "") res ="0";
        return res;
    }

    bign operator + (const bign& b) const {
        bign c;
        c.len =0;

        for( int i=0; g=0;  g || i<max(len,b.len); i++ ){
            int x=g
            if(i<len) x+=s[i];
            if(i<b.len) x+=b.s[i];
            c.s[c.len++] = x%10;
            g = x/10;//g is carry
        }

        return c;
        
    }
};

istream& operator >> (istream &in, bign& x){
    string s;
    in>>s;
    x=s.c_str();
    return in;
}

ostream& operator << (ostream& out,const bign& x){
    out<<x->str();
    return out;
}


