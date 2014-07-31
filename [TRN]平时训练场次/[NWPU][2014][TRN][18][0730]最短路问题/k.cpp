//K
//每次枚举等级范围然后求一遍spfa，找出最小值
//建图的时候，对每个人，连一条源点到他的边，权为他持有物品的价值，再连代替品持有者到他的边，边权为用代替品后的优惠价
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int map[105][105];
int dist[105];
char flag[105];
char enable[105];
char ls[105];
int n;

void spfa()
{
	queue<int> q;
	int t;
	memset(flag,0,sizeof(flag));
	memset(dist,127,sizeof(dist));
	dist[0]=0;
	flag[0]=1;
	q.push(0);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		flag[t]=0;
		for(int i=0;i<=n;i++)
		{
			if(enable[i]==0)
				continue;
			if(dist[i]>dist[t]+map[t][i])
			{
				dist[i]=dist[t]+map[t][i];
				if(flag[i]==0)
				{
					flag[i]=1;
					q.push(i);
				}
			}
		}
	}
}

int main()
{
	int m;
	int t,a,b;
	int maxl,min;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		memset(map,127,sizeof(map));
		memset(enable,0,sizeof(enable));
		memset(ls,0,sizeof(ls));
		maxl=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&map[0][i],&ls[i],&t);
			if(ls[i]>maxl)
				maxl=ls[i];
			for(int j=0;j<t;j++)
			{
				scanf("%d%d",&a,&b);
				map[a][i]=b;
			}
		}
		a=ls[1]-m;
		if(a<0)
			a=0;
		b=a+m;
		if(b>maxl)
			b=maxl;
		min=2147483600;
		while(b<=maxl)
		{
			for(int i=1;i<=n;i++)
			{
				if(ls[i]>=a&&ls[i]<=b)
				{
					enable[i]=1;
				}
				else
				{
					enable[i]=0;
				}
			}
			spfa();
			if(dist[1]<min)
				min=dist[1];
			a++;
			b++;
		}
		printf("%d\n",min);
	}
}
