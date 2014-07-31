//I
//裸SPFA,直接输入邻接矩阵……
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int map[105][105];
int dist[105];
char flag[105];
int n;

void spfa(int s)
{
	queue<int> q;
	int t;
	memset(dist,127,sizeof(dist));
	memset(flag,0,sizeof(flag));
	flag[s]=1;
	dist[s]=0;
	q.push(s);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		flag[t]=0;
		for(int i=1;i<=n;i++)
		{
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
	char str[100];
	int v;
	while(scanf("%d",&n)!=EOF)
	{
		memset(map,127,sizeof(map));
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				scanf("%s",str);
				if(str[0]=='x')
				{

				}
				else
				{
					sscanf(str,"%d",&v);
					map[i][j]=v;
					map[j][i]=v;
				}
			}
		}
		spfa(1);
		v=0;
		for(int i=1;i<=n;i++)
		{
			if(v<dist[i])
				v=dist[i];
		}
		printf("%d\n",v);
	}
	return 0;
}
