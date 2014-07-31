//A
//最短路不解释
//SPFA大法好，注意无向图两个方向的边都要连
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int map[1005][1005];
int dist[1005];
int flag[1005];
int n;

void spfa(int s)
{

	memset(dist,127,sizeof(dist));
	memset(flag,0,sizeof(flag));
	queue<int> que;
	que.push(s);
	flag[s]=1;
	dist[s]=0;
	int t;
	while(!que.empty())
	{
		t=que.front();
		que.pop();

		flag[t]=0;
		for(int i=1;i<=n;i++)
		{
			if(dist[i]>dist[t]+map[t][i])
			{
				dist[i]=dist[t]+map[t][i];
				if(flag[i]==0)
				{
					que.push(i);
					flag[i]=1;
				}
			}
		}
	}
}

int main()
{
	int t;
	int a,b,c;
	while(scanf("%d%d",&t,&n)!=EOF)
	{

	memset(map,127,sizeof(map));

	for(int i=0;i<t;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(map[a][b]>c)
		{
			map[a][b]=c;
			map[b][a]=c;
		}
	}

	spfa(1);
	printf("%d\n",dist[n]);
	}
	return 0;
}
