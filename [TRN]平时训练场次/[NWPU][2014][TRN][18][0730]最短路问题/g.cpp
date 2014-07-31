//G
//求路径上最长边的最短值
//dist[i]数组的意义为走到第i点时最长边的最短值，再用spfa大法
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;
struct Position
{
	int x, y;
};

int map[205][205];
Position ps[205];
int dist[205];
int flag[205];
int max;
int max2(int a,int b)
{
	return a>b?a:b;
}
int spfa(int n)
{
	queue<int> q;
	int t;
	memset(dist,127,sizeof(dist));
	memset(flag,0,sizeof(flag));
	flag[1]=1;
	dist[1]=0;
	q.push(1);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		flag[t]=0;
		for(int i=1;i<=n;i++)
		{
			if(i==t)
				continue;			
			if(dist[i]>max2(dist[t],map[t][i]))
			{				
				dist[i]=max2(dist[t],map[t][i]);				
				if(flag[i]==0)
				{
					flag[i]=1;
					q.push(i);
				}
			}
		}
	}
}

int dist22(Position a,Position b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main()
{
	int n;
	int iii=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		iii++;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&ps[i].x,&ps[i].y);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
					map[i][j]=2147483646;
				else
					map[i][j]=dist22(ps[i],ps[j]);
			}
		}
		spfa(n);
		printf("Scenario #%d\nFrog Distance = %.03f\n\n",iii,sqrt(dist[2]));
	}
}

