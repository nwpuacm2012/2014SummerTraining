//F
//反向排序，数据量大要用邻接表，本代码是vector实现邻接表
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> map[30002];
int in[30002];
int ans[30002];

int chkab(int a,int b)
{
	int l=map[a].size();
	for(int i=0;i<l;i++)
	{
		if((map[a])[i]==b)
			return 1;
	}
	return 0;
}
int main()
{
	int T,m,n;
	int t;
	int a,b,l;
	priority_queue<int> que;
	scanf("%d",&T);
	for(int iii=0;iii<T;iii++)
	{
		scanf("%d%d",&n,&m);

		memset(in,0,sizeof(in));
		for(int i=1;i<=n;i++)
		{
			map[i].clear();
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			if(chkab(b,a)==0)
			{
				in[a]+=1;
				map[b].push_back(a);
			}
		}

		for(int i=1;i<=n;i++)
		{
			if(in[i]==0)
				que.push(i);
		}

		for(int i=0;i<n;i++)
		{
			t=-1;
			t=que.top();
			que.pop();
			in[t]--;
			ans[i]=t;
			l=map[t].size();
			for(int j=0;j<l;j++)
			{
				a=(map[t])[j];
				in[a]--;
				if(in[a]==0)
					que.push(a);

			}
		}
		printf("%d",ans[n-1]);
		for(int i=n-2;i>=0;i--)
					printf(" %d",ans[i]);
		printf("\n");
	}
}
