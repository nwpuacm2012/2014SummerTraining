//G
//拓扑排序判断是否有三元环
//判断是否有环即可
//证明：
//假设有n元环，a->b->c……->a，若c->a有边，则存在三角形环 a->b->c->a 
//若无边，则说明不存在c->a的边从而存在a->c的边，于是有n元环a->b->c……->a变成有n-1元环a->c……->a
//最终可以证明存在 三角形环。
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int in[2005];
char map[2005][2005];

int tps(int n)
{
	int f=-1,t,t2,l;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		t=-1;
		for(int j=0;j<n;j++)
		{
			if(in[j]==0)
			{
				t=j;
				break;
			}
		}
		if(t==-1)
			return 1;
		in[t]--;
		for(int j=0;j<n;j++)
		{
			if(map[t][j]=='1'&&in[j]!=0)
				in[j]--;
		}
	}

	return 0;
}

int main()
{
	int T,n,t,a;
	scanf("%d",&T);
	for(int iii=1;iii<=T;iii++)
	{

		memset(in,0,sizeof(in));
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{

			scanf("%s",map[i]);
			for(int j=0;j<n;j++)
			{
				if(map[i][j]=='1')
				{
					in[j]+=1;
				}
			}
		}
		t=tps(n);
		if(t==0)
		{
			printf("Case #%d: No\n",iii);
		}
		else
		{
			printf("Case #%d: Yes\n",iii);
		}
	}
}

