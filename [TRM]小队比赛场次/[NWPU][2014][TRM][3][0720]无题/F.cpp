/**
 * @author neko01
 */
//#pragma comment(linker, "/STACK:102400000,102400000")
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
using namespace std;
struct point{
	double x,y;
}a[100001];
int ans=0;
double r,ax, ay, az, dx, dy, dz;
void solve()
{
	double aa,b,c,d;
	aa=dx*dx+dy*dy+dz*dz;
	b=2*(ax*dx+ay*dy+az*dz);
	c=ax*ax+ay*ay+az*az-r*r;
	d=b*b-4*aa*c;
	if(d<0)
		return;
	a[ans].x=(b*(-1)-sqrt(d))/(aa*2);
	a[ans].y=(b*(-1)+sqrt(d))/(aa*2);
	if(a[ans].x<0&&a[ans].y<0)
		return;
	ans++;
}
bool cmp(struct point a,struct point b)
{
	return a.y<b.y;
}
int main()
{
	int t,n,cnt=0;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%lf",&n,&r);
		int time=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&az,&dx,&dy,&dz);
			solve();
		}
		printf("Case %d: ",++cnt);
		sort(a,a+ans,cmp);
		int i=1;
		for(int k=0;k<ans;k++)
		{
			time++;
			while(a[k].y>=a[i].x)
			{
				i++;
				if(i>=ans)
					break;
			}
			k=i-1;
		}
		printf("%d %d\n",ans,time);
	}
	return 0;
}