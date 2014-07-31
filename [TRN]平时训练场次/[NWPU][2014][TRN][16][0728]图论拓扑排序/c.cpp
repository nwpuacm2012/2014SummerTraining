//C
//反向拓扑排序，每次尽量取大的
#include <cstdio>
#include <cstring>

int map[501][501];
int in[501];
int ans[501];

int solve(int n)
{	
	int f,t;
	for(int i=n;i>0;i--)
	{

		f=0;
		t=-1;
		for(int j=n-1;j>=0;j--)
		{
			if(in[j]==0)
			{
				f=1;
				t=j;
				break;
			}
		}
		if(t==-1)
		{
			printf("-1\n");
			return -1;
		}
		ans[t]=i;
		in[t]--;

		for(int j=0;j<n;j++)
		{
			if(map[t][j]==1)
			{
				in[j]--;
			}
		}
	}
	printf("%d",ans[0]);
	for(int i=1;i<n;i++)
		printf(" %d",ans[i]);
		printf("\n");
	return 0;
}

int main()
{
	int T;
	int n,m;
	int a,b;
	scanf("%d",&T);
	for(int iii=0;iii<T;iii++)
	{
		memset(map,0,sizeof(map));
		memset(in,0,sizeof(in));
		memset(ans,0,sizeof(ans));
		scanf("%d%d",&n,&m);

		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);

			a-=1;
			b-=1;
			if(map[b][a]==0)
			{
				in[a]+=1;
			}
			map[b][a]=1;
		}
		solve(n);
	}
}

