//B
//最小生成树
//同A题，代码都基本一样的……
#include <cstdio>
#include <cstring>

struct Position
{
	int x;
	int y;
};
Position pos[755];
int map[755][755];
int dist[755];
int dist2[755];

int dist22(Position a,Position b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
long long ans;
void prim(int n)
{
	memset(dist,127,sizeof(dist));

	ans=0;
	for(int i=1;i<=n;i++)
	{
		dist[i]=map[1][i];
		dist2[i]=1;
	}
	dist[1]=0;
	dist2[1]=-1;


	int min,t;
	for(int k=1;k<n;k++)
	{
		min=1073741824;
		t=-1;
		for(int i=1;i<=n;i++)
		{
			if(dist2[i]!=-1&&dist[i]<min)
			{
				min=dist[i];
				t=i;
			}
		}

		if(min!=0)
		{
			ans+=dist[t];
		}
		dist2[t]=-1;

		for(int i=1;i<=n;i++)
		{
			if(dist2[i]!=-1&&map[t][i]<dist[i])
			{
				dist[i]=map[t][i];
				dist2[i]=t;
			}
		}

	}
}

int main()
{
	int n,m,t,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		memset(map,127,sizeof(map));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			map[a][b]=0;
			map[b][a]=0;
		}
		prim(n);
		printf("%I64d\n",ans);
		//printf(">>>>>>>>>\n");
	}
	return 0;
}

