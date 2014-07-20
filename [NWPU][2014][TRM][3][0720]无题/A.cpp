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

int num[1000];
int sum[1000];
int ans=0;
int main()
{
  int t;cin>>t;int m,n;
  while(t--)
  {
      cin>>m>>n;
      for(int i=0;i<m;i++)
        cin>>num[i];
      for(int i=m;i<2*m;i++)
        num[i]=num[i-m];
        sum[0]=num[0];
      for(int i=1;i<2*m;i++)
        sum[i]=sum[i-1]+num[i];
        ans=sum[n-1];
      for(int i=n;i<2*m;i++)
      {
          ans=max(ans,sum[i]-sum[i-n]);
      }
      cout<<ans<<endl;
  }
   return 0;
}