//D
//求最大可通过的流量
//Dijkstra，把dist[i]的意义改为到i点时，中间经过最卡的一条路流量最多是多少
#include <cstdio>
#include <cstring>

int map[1002][1002];
int n,m;
int dist[1002];
int vis[1002];

int min(int a,int b)
{
	return a<b?a:b;
}

int dijkstra(int s)
{
	memset(dist,0,sizeof(dist));
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	int max,t;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		dist[i]=map[s][i];
	}
	for(int i=1;i<=n;i++)
	{
		max=0;
		t=-1;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==0&&max<dist[j])
			{
				t=j;
				max=dist[j];
			}
		}
		ans+=max;
		vis[t]=1;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==0&&dist[j]<min(map[t][j],max))
			{
				dist[j]=min(map[t][j],max);
			}
		}
	}
	return ans;
}


int main()
{
	int T;
	int a,b,c;
	scanf("%d",&T);
	for(int iii=1;iii<=T;iii++)
	{
		scanf("%d%d",&n,&m);
		memset(map,0,sizeof(map));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			map[a][b]=c;
			map[b][a]=c;
		}
		dijkstra(1);
		printf("Scenario #%d:\n%d\n\n",iii,dist[n]);
	}
}
