//I
//度的序列转换为图
//每次取度最大的点，拿其他的点里度大的跟他连，然后更新一遍剩余的度，直到连完或出现负度
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Lake
{
	int d;
	int num;
	int vis;
};

int map[15][15];
Lake lake[15];

bool cmp(Lake a,Lake b)
{
	return a.d>b.d;
}

int main()
{
	int T,n,f,cnt,p,tn;
	scanf("%d",&T);
	for(int iii=0;iii<T;iii++)
	{
		memset(map,0,sizeof(map));
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&lake[i].d);
			lake[i].num=i;
			lake[i].vis=0;
		}
		f=0;
		for(int i=0;i<n;i++)
		{
			//printf("chk %d\t",i);
			sort(lake,lake+n,cmp);
			//printf("lake[%d].d=%d\n",lake[0].num,lake[0].d);
			if(lake[0].d<0)
			{
				f=1;
				break;
			}
			cnt=0;
			p=1;
			lake[0].vis=1;
			tn=lake[0].d;
			lake[0].d=0;
			while(cnt<tn)
			{
				//printf("cnt=%d  p=%d  num=%d  d=%d  vis=%d\n",cnt,p,lake[p].num,lake[p].d,lake[p].vis);
				if(lake[p].d==0)
				{
					f=1;
					//printf("%d %d %d\n",p,lake[p].d,cnt);
					break;
				}
				if(lake[p].vis==0)
				{
					lake[p].d-=1;
					map[lake[0].num][lake[p].num]=1;
					map[lake[p].num][lake[0].num]=1;
					cnt++;
				}
				if(f==1)
					break;
				p++;
			}

		}
		if(f==1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n-1;j++)
				{
					printf("%d ",map[i][j]);
				}
				printf("%d\n",map[i][n-1]);
			}
		}
		if(iii!=T-1)
			printf("\n");
	}
}
