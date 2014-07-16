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
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int ans=0;
    for(int i=0;i<str1.size();i++){
        for(int j=0;j<str2.size();j++)
        {
            ans+=(str1[i]-'0')*(str2[j]-'0');
        }
    }
    cout<<ans<<endl;
    return 0;
}