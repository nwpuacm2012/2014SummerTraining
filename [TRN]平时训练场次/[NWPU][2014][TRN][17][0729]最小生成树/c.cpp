//C
//求最小生成树的最长边
//跟AB基本一样
#include <cstdio>
#include <cstring>


int map[2001][2001];
int dist[2001];
int dist2[2001];


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
			if(dist[t]>ans)
				ans=dist[t];
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
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(map,127,sizeof(map));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&t);
			if(t<map[a][b])
			{
				map[a][b]=t;
				map[b][a]=t;
			}

		}
		prim(n);
		printf("%I64d\n",ans);
		//printf(">>>>>>>>>\n");
	}
	return 0;
}


