#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <iostream>


using namespace std;

vector<int> vec;
int finda(int a,int b,int c)
{
    vec.clear();
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    vec.push_back(a+b);
    vec.push_back(a+c);
    vec.push_back(b+c);
    vec.push_back(a+b+c);
    vec.push_back(a-b);
    vec.push_back(a-c);
    vec.push_back(b-a);
    vec.push_back(b-c);
    vec.push_back(c-a);
    vec.push_back(c-b);
    vec.push_back(a+b-c);
    vec.push_back(a+c-b);
    vec.push_back(b+c-a);
    vec.push_back(a-b-c);
    vec.push_back(b-a-c);
    vec.push_back(c-a-b);
    sort(vec.begin(),vec.end());
    int ans=0;
    int t=-1000000l;
    for(int i=0;i<vec.size();i++)
        if(vec[i]>0&&vec[i]!=t)
        {
            ans++;
            t=vec[i];
        }
    return ans;
}
int a,b;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int ans=0;
        for(int i=1; i<=a/2; i++)
        {
            ans=max(ans,finda(a-i,i,b));
        }
        swap(a,b);
        for(int i=1; i<=a/2; i++)
        {
            ans=max(ans,finda(a-i,i,b));
        }
        cout<<ans<<endl;
    }
}