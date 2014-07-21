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
const int N=100000+5;
int a[N];
int main()
{
    int M,T,U,F,D;
    char str;
    int ans=0;
    bool isFind=false;
    cin>>M>>T>>U>>F>>D;
    for(int i=0;i<T;i++)
    {
        cin>>str;
        if(!isFind)
        {
            int tmp;
            if(str=='u'||str=='d')
                tmp=U+D;
            else    tmp=2*F;
            if(M<tmp)
            {
                ans=i;
                isFind=true;
            }
            else
            {
                M-=tmp;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}