//多线程DP
//f[i][j][k][l]表示两次分别走到(i,j),(k,l)时的最大值
#include <cstdio>
#include <cstring>

int map[35][35];
int f[35][35][35][35];
int n;

void solve()
{
	memset(f,0,sizeof(f));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				for(int l=0;l<n;l++)
				{

					f[i][j][k][l]=0;
					if(i>0&&k>0&&f[i-1][j][k-1][l]>f[i][j][k][l])
						f[i][j][k][l]=f[i-1][j][k-1][l];
					if(i>0&&l>0&&f[i-1][j][k][l-1]>f[i][j][k][l])
						f[i][j][k][l]=f[i-1][j][k][l-1];
					if(j>0&&k>0&&f[i][j-1][k-1][l]>f[i][j][k][l])
						f[i][j][k][l]=f[i][j-1][k-1][l];
					if(i>0&&l>0&&f[i][j-1][k][l-1]>f[i][j][k][l])
						f[i][j][k][l]=f[i][j-1][k][l-1];
					if(i==k&&j==l)
						f[i][j][k][l]+=map[i][j];
					else
						f[i][j][k][l]+=map[i][j]+map[k][l];
				}
			}
		}
	}
	printf("%d\n",f[n-1][n-1][n-1][n-1]);
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		solve();
	}
	return 0;
}
