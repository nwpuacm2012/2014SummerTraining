//F
//兑换货币，dist[i]表示兑换到第i种货币时获得的最大钱数
//SPFA，用cnt数组记录进队次数，大于n次则有环（可以无限刷钱）
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
double mapr[105][105];
double mapc[105][105];
double dist[105];
int cnt[105];
int flag[105];
int n;

int spfa(int s,double init)
{
	queue<int> q;
	int t;
	double d;
	memset(dist,0,sizeof(dist));
	memset(cnt,0,sizeof(cnt));
	memset(flag,0,sizeof(flag));
	dist[s]=init;
	flag[s]=1;
	q.push(s);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		flag[t]=0;
		for(int i=1;i<=n;i++)
		{
			d=(dist[t]-mapc[t][i])*mapr[t][i];			
			if(d>dist[i])
			{				
				cnt[i]++;
				if(cnt[i]>n+1)
					return 1;
				dist[i]=d;
				if(flag[i]==0)
				{
					flag[i]=1;
					q.push(i);
				}
			}
		}
	}
	if(dist[s]>init)
		return 1;
	return 0;
}

int main()
{
	int m,s;
	int a,b;
	double init;
	while(scanf("%d%d%d%lf",&n,&m,&s,&init)!=EOF)
	{
		memset(mapr,0,sizeof(mapr));
		memset(mapc,0,sizeof(mapc));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			scanf("%lf%lf%lf%lf",&mapr[a][b],&mapc[a][b],&mapr[b][a],&mapc[b][a]);
		}
		a=spfa(s,init);
		if(a==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

