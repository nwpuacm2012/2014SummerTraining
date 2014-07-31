//A
//已经有路的边权为0，输出的时候判断一下如果是0则不输出
//边权存距离的平方省去开方运算（存距离也可）
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

void prim(int n)
{
	memset(dist,127,sizeof(dist));


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
			printf("%d %d\n",t,dist2[t]);
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
			scanf("%d%d",&pos[i].x,&pos[i].y);

		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				t=dist22(pos[i],pos[j]);
				map[i][j]=t;
				map[j][i]=t;
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
		//printf(">>>>>>>>>\n");
	}
	return 0;
}
