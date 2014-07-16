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
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x,sum=0,ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			ans+=x*(n-x-1);
		}
		sum=n*(n-1)*(n-2)/6;
		ans/=2;
		printf("%.3lf\n",(sum-ans)*1.0/sum);
	}
	return 0;
}
