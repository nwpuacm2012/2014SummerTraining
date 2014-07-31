//C
//求所有点到一点的最短路，把所有边反向之后求那一点到其他带你的最短路即可
//本弱简单粗暴存两张图，用vector邻接表导致本代码在poj超上会超时
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

struct Edge
{
	int n,v;
};

vector<Edge> map[1000002];
vector<Edge> map2[1000002];
long long dist[1000002];
char flag[1000002];
int n,m;

void spfa1()
{
	memset(dist,127,(n+2)*sizeof(long long));
	memset(flag,0,(n+2)*sizeof(char));
	int t,l,t2,t3;
	queue<int> q;
	dist[1]=0;
	flag[1]=1;
	q.push(1);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		flag[t]=0;
		l=map[t].size();
		for(int i=0;i<l;i++)
		{
			t2=(map[t])[i].n;
			t3=(map[t])[i].v;
			if(dist[t2]>dist[t]+t3)
			{
				dist[t2]=dist[t]+t3;
				if(flag[t2]==0)
				{
					flag[t2]=1;
					q.push(t2);
				}

			}
		}

	}
}

void spfa2()
{
	memset(dist,127,(n+2)*sizeof(long long));
	memset(flag,0,(n+2)*sizeof(char));
	int t,l,t2,t3;
	queue<int> q;
	dist[1]=0;
	flag[1]=1;
	q.push(1);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		flag[t]=0;
		l=map2[t].size();
		for(int i=0;i<l;i++)
		{
			t2=(map2[t])[i].n;
			t3=(map2[t])[i].v;
			if(dist[t2]>dist[t]+t3)
			{
				dist[t2]=dist[t]+t3;
				if(flag[t2]==0)
				{
					flag[t2]=1;
					q.push(t2);
				}

			}
		}

	}
}


int main()
{
	int T;
	int a,b,c;
	long long ans;
	Edge e;
	scanf("%d",&T);
	for(int iii=0;iii<T;iii++)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			map[i].clear();
			map2[i].clear();
		}
        for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			e.n=b;
			e.v=c;
			map[a].push_back(e);
			e.n=a;
			map2[b].push_back(e);
		}
		ans=0;
		spfa1();
		for(int i=1;i<=n;i++)
		{

			ans+=dist[i];
		}

		spfa2();
		for(int i=1;i<=n;i++)
		{

			ans+=dist[i];
		}


		printf("%I64d\n",ans);
	}
}

