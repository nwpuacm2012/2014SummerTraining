//E
//先求最小生成树，再拿s颗卫星搞定s-1条边，剩下的最长边即为答案
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
struct Position
{
	int x;
	int y;
};
Position pos[555];
int map[555][555];
int dist[555];
int dist2[555];
int ans[505];
int dist22(Position a,Position b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

void prim(int n,int m)
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

		ans[k]=dist[t];
		//printf("%d\n",ans[k]);
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
	sort(ans+1,ans+n);
	printf("%.02f\n",sqrt(ans[n-m]));
}

int main()
{
	int n,m,t,a,b;
	int T;
	scanf("%d",&T);
	for(int iii=0;iii<T;iii++)
	{
		scanf("%d%d",&m,&n);
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

		prim(n,m);
		//printf(">>>>>>>>>\n");
	}
	return 0;
}
