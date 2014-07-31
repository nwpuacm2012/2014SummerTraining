//J
//对每个关系连一条有向边，从图上看，如果一头牛，他能到的点和能到他的点的和为n-1，则可以确定他的位置
#include <cstdio>
#include <cstring>
#define inf 0x01010101

int map[105][105];
int n,m;
int d1[105];
int d2[105];
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(map[i][k]==1&&map[k][j]==1)
					map[i][j]=1;
			}
		}
	}
}

int main()
{
	int a,b;
	int cnt;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(map,0,sizeof(map));
		memset(d1,0,sizeof(d1));
		memset(d2,0,sizeof(d2));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			map[a][b]=1;
		}
		cnt=0;
		floyd();
		for(int i=1;i<=n;i++)
		{
			a=0;
			for(int j=1;j<=n;j++)
			{
				a+=map[i][j]+map[j][i];
			}
			if(a==n-1)
				cnt++;
		}
		printf("%d\n",cnt);

	}
}
