//D
//求最小生成树，特判题，答案合理即可
//本代码是克鲁斯卡尔算法
#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct
{
	int s,e,l;
} Edge;

int f[1005];
Edge edge[15005];
Edge ans[15005];
int maxl;

int cmp(Edge a,Edge b)
{
	return a.l<b.l;
}
int gf(int x)
{
	if(f[x]==x)
		return x;
	f[x]=gf(f[x]);
	return f[x];
}

int unite(int x,int y)
{
	int fx=gf(x);
	int fy=gf(y);
	if(fx==fy)
		return 0;
	f[fy]=fx;
	return 1;
}

void mst(int n)
{
	int cnt=0;
	int pos=0;
	int a,b,c;
	maxl=0;
	while(cnt<n-1)
	{
		a=edge[pos].s;
		b=edge[pos].e;
		c=edge[pos].l;
		if(unite(a,b)==1)
		{
			ans[cnt]=edge[pos];
			if(c>maxl)
				maxl=c;
			cnt++;
		}
		pos++;
	}
	printf("%d\n%d\n",maxl,n-1);
	for(int i=0;i<cnt;i++)
	{
		printf("%d %d\n",ans[i].s,ans[i].e);
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&edge[i].s,&edge[i].e,&edge[i].l);
	}
	sort(edge,edge+m,cmp);
	mst(n);
}
