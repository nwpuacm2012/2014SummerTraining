#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define INF 0x7fffffff
const double eps=1e-8;
const double pi=acos(-1.0);
const int N=100005;
char a[N],b[N];
int main()
{
    while(~scanf("%s%s",a,b))
    {
        char *p,*q;
        for(p=a,q=b;*p!=0;p++,q++)
        {
            while(*p!=*q&&*q!='\0')
                q++;
            if(*q==0)
                break;
        }
        if(*p!=0)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}