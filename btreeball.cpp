/*************************************************************************
	> File Name: btreeball.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2013年11月24日 星期日 14时15分32秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>

int main(){
    int D,I;
    while(scanf("%d%d",&D,&I) == 2){
        int k = 1;
        for(int i = 0; i< D-1; i++){
            if(I%2) {
                k = k*2;
                I=(I+1)/2;

            } else {
                k= 2*k+1;
                I/=2;
            }
        }

        printf("%d\n",k);
    }
}
