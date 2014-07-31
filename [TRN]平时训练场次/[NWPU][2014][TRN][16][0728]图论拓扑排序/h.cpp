//H
//拓扑排序不解释……
#include <cstdio>
#include <cstring>
int map[105][105];
int in[105];
int ans[105];
int main()
{
	int n,a,t;
	scanf("%d",&n);
	memset(map,0,sizeof(map));
	memset(ans,0,sizeof(ans));
	memset(in,0,sizeof(in));
	for(int i=1;i<=n;i++)
	{
		while(1)
		{
			scanf("%d",&a);
			if(a==0)
				break;
			if(map[i][a]==0)
				in[a]+=1;
			map[i][a]=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(in[j]==0)
			{
				t=j;
				break;
			}
		}
		in[t]--;
		ans[i]=t;
		for(int j=1;j<=n;j++)
		{
			if(map[t][j]==1)
				in[j]--;
		}
	}
	printf("%d",ans[0]);
	for(int i=1;i<n;i++)
	{
		printf(" %d",ans[i]);
	}
	return 0;
}

