/*************************************************************************
	> File Name: strlen.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Sep 2014 11:14:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


size_t strlen(const char *str)
{
    const char *s;
    for(s=str; *s; s++);

    return s-str;
}

char* strcpy(char *to, const char *from)
{
    assert(to != NULL && from != NULL);

    char *p = to;

    while((*p++ = *from++) != '\0');

    return to;
    

}


