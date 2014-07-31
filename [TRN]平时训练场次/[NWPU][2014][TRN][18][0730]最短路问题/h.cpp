//H
//先用floyd求出任意两点间的最短路，然后枚举每一个点，求出这个点到其他点的最短路的最大值，再在这些最大值里找出最小值

#include <cstdio>
#include <cstring>
#define inf 0x01010101

int map[105][105];
int n;

void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(map[i][k]+map[k][j]<map[i][j])
					map[i][j]=map[i][k]+map[k][j];
			}
		}
	}
}

int main()
{
	int t,a,b;
	int min,max;
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		memset(map,1,sizeof(map));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&t);
			for(int j=0;j<t;j++)
			{
				scanf("%d%d",&a,&b);
				if(map[i][a]>b)
				{
					map[i][a]=b;
				}
			}
		}

		floyd();

		min=inf;
		for(int i=1;i<=n;i++)
		{
			max=0;
			for(int j=1;j<=n;j++)
			{
				if(i==j)
					continue;
				if(max<map[i][j])
					max=map[i][j];
			}
			if(max<min)
			{
				min=max;
				t=i;
			}
		}
		if(min==inf)
		{
			printf("disjoint\n");
		}
		else
		{
			printf("%d %d\n",t,min);
		}

	}
}
