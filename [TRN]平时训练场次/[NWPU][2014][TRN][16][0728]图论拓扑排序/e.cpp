//D
//这次是正向排……
#include <cstdio>
#include <cstring>

int map[701][701];
int in[701];
int ans[701];

int solve(int n)
{

	int t;
	for(int i=1;i<=n;i++)
	{
		t=-1;
		for(int j=1;j<=n;j++)
		{
			if(in[j]==0)
			{
				in[j]--;
				t=j;
				ans[i]=j;
				break;
			}
		}
		if(t==-1)
		{
			printf("-1\n");
			return -1;
		}
		for(int j=1;j<=n;j++)
		{
			if(map[t][j]==1)
			{
				in[j]--;
			}
		}
	}
	printf("%d",ans[1]);
	for(int i=2;i<=n;i++)
		printf(" %d",ans[i]);
	printf("\n");
	return 0;
}

int main()
{
	int T;
	int n,m;
	int a,b;
	//scanf("%d",&T);
	T=1;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(map,0,sizeof(map));
		memset(in,0,sizeof(in));
		memset(ans,0,sizeof(ans));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			//printf(">>>%d %d\n",a,b);
			if(map[a][b]==0)
			{
				in[b]+=1;
			}
			map[a][b]=1;
		}

		solve(n);
	}
	return 0;
}

