//B
//最短路
//输入神蛋疼，小心重边
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

struct Node
{
	double x,y;
	int f;
};

Node node[800];

double map[800][800];
double dist[800];
int flag[800];
int n;

double getdist(Node a,Node b,int f)
{
	double d=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	if(f==1)
		d/=(40000.0/60.0);
	else
		d/=(10000.0/60.0);
	return d;
}

void spfa(int s)
{
	queue<int> q;
	memset(flag,0,sizeof(flag));
	memset(dist,0x7f,sizeof(dist));
	dist[s]=0;
	flag[s]=1;
	q.push(s);
	int t;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		flag[t]=0;
		for(int i=1;i<n;i++)
		{
			if(dist[i]>dist[t]+map[t][i])
			{
				dist[i]=dist[t]+map[t][i];
				if(flag[i]==0)
				{
					q.push(i);
					flag[i]=1;
				}
			}
		}
	}


}

int main()
{
	//freopen("in.txt","r",stdin);
	int a,b;
	int l,r;
	double d;
	n=1;
	scanf("%d%d",&a,&b);
	node[n].x=a;
	node[n].y=b;
	node[n].f=0;
	n++;
	scanf("%d%d",&a,&b);
	node[n].x=a;
	node[n].y=b;
	node[n].f=0;
	n++;
	l=n;
	memset(map,0x7f,sizeof(map));
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a==-1&&b==-1)
		{

			for(int i=l;i<n-1;i++)
			{
				map[i][i+1]=getdist(node[i],node[i+1],1);
				map[i+1][i]=map[i][i+1];
			}
			l=n;
			continue;
		}
		node[n].x=a;
		node[n].y=b;
		node[n].f=1;
		n++;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			d=getdist(node[i],node[j],0);
			if(d<map[i][j])
				map[i][j]=d;
		}
	}
	spfa(1);	
	printf("%.0f\n",dist[2]);
	return 0;
}
