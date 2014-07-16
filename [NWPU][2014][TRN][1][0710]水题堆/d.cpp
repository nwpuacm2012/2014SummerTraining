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
const int maxn=50000+5;
struct Select{
    int A,B;
    int pos;
    Select(int A=0,int B=0,int pos=0):A(A),B(B),pos(pos){};
}a[maxn];
bool cmp(const Select& a,const Select& b)
{
    if(a.A!=b.A)    return a.A>b.A;
    else    return a.B>b.B;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].A,&a[i].B);
        a[i].pos=i+1;
    }
    sort(a,a+n,cmp);
    int maxL=-INF,ipos=0;
    for(int i=0;i<k;i++)
    {
        if(maxL<a[i].B)
        {
            maxL=a[i].B;
            ipos=a[i].pos;
        }
    }
    printf("%d\n",ipos);
    return 0;
}