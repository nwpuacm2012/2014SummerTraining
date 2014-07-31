//F
//同A题，两球间的距离d=球心距离-两球半径和，d<0 => d=0
//prim大法搞定
#include <cstdio>
#include <cstring>
#include <cmath>
struct Position
{
	double x,y,z,r;
};
Position pos[155];
double map[155][155];
double dist[155];

int dist2[155];
double ans;
double dist22(Position a,Position b)
{
	double d=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
	d-=a.r+b.r;
	if(d<0)
		return 0;
	return d;
}

void prim(int n)
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		dist[i]=map[1][i];
		dist2[i]=1;
	}
	dist[1]=0;
	dist2[1]=-1;

	double min;
	int t;
	for(int k=1;k<n;k++)
	{
		min=10000.0;
		t=-1;
		for(int i=1;i<=n;i++)
		{
			if(dist2[i]!=-1&&dist[i]<min)
			{
				min=dist[i];
				t=i;
			}
		}
		if(min!=0)
		{
			ans+=dist[t];
		}
		dist2[t]=-1;

		for(int i=1;i<=n;i++)
		{
			if(dist2[i]!=-1&&map[t][i]<dist[i])
			{
				dist[i]=map[t][i];
				dist2[i]=t;
			}
		}

	}
}

int main()
{
	int n,m,a,b;
	double t;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				map[i][j]=10000.0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf%lf",&pos[i].x,&pos[i].y,&pos[i].z,&pos[i].r);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				t=dist22(pos[i],pos[j]);

				map[i][j]=t;
				map[j][i]=t;
			}
		}
		prim(n);
		printf("%.03f\n",ans);
		//printf(">>>>>>>>>\n");
	}

	return 0;
}

