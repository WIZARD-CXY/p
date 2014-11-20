/*************************************************************************
	> File Name: hanoi.c
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Nov 2014 12:15:50 PM CST
 ************************************************************************/

#include<stdio.h>

// param n yuanpan num
// x source towel num
// y auxillary towel num
// z target towel num
void hanoi(int n, char x, char y, char z){

    if(n==1){
        printf("%d from %c to %c\n",n, x, z);
    } else {
        // move the 1 to n-1 number of pan to y ,z is auxillary towel
        hanoi(n-1,x,z,y);
        // move the num n pan from x to z
        printf("%d from %c to %c\n",n, x, z);
        // move the 1 to n-1 pan from y to z ,auxillary towel is x
        hanoi(n-1,y,x,z);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",(1<<n)-1); // total num
    hanoi(n,'A','B','C');
}
