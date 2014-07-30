#include <cstdio>
#include <cstring>

int n;
char sym[55];
int num[55];
int f[55][55][2];

int ans[55];
int main()
{
	int max,min,cnt;
	memset(sym,0,sizeof(sym));
	memset(num,0,sizeof(num));
	memset(f,0,sizeof(f));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf(" %c%d",&sym[i],&num[i]);
	}
	for(int i=0;i<n;i++)
	{
		f[i][0][0]=num[i];
		f[i][0][1]=num[i];
	}
	for(int j=1;j<n;j++)
	{
		for(int i=0;i<n;i++)
		{
			max=0x80000000;
			min=0x7fffffff;

			for(int k=0;k<j;k++)
			{
				if(sym[(i+k+1)%n]=='t')
				{
					if(f[i][k][0]+f[(i+k+1)%n][j-k-1][0]>max)
						max=f[i][k][0]+f[(i+k+1)%n][j-k-1][0];
					if(f[i][k][1]+f[(i+k+1)%n][j-k-1][1]<min)
						min=f[i][k][1]+f[(i+k+1)%n][j-k-1][1];
				}
				else
				{
					if(f[i][k][0]*f[(i+k+1)%n][j-k-1][0]>max)
						max=f[i][k][0]*f[(i+k+1)%n][j-k-1][0];
					if(f[i][k][1]*f[(i+k+1)%n][j-k-1][1]>max)
						max=f[i][k][1]*f[(i+k+1)%n][j-k-1][1];
					if(f[i][k][0]*f[(i+k+1)%n][j-k-1][1]<min)
						min=f[i][k][0]*f[(i+k+1)%n][j-k-1][1];
					if(f[i][k][1]*f[(i+k+1)%n][j-k-1][0]<min)
						min=f[i][k][1]*f[(i+k+1)%n][j-k-1][0];
					if(f[i][k][1]*f[(i+k+1)%n][j-k-1][1]<min)
						min=f[i][k][1]*f[(i+k+1)%n][j-k-1][1];
				}
			}
			f[i][j][0]=max;
			f[i][j][1]=min;
		}
	}
	max=0x80000000;
	for(int i=0;i<n;i++)
	{
		if(f[i][n-1][0]>max)
			max=f[i][n-1][0];
	}
	cnt=0;
	for(int i=0;i<n;i++)
	{
		if(f[i][n-1][0]==max)
		{
			ans[cnt]=i+1;
			cnt++;
		}
	}
	printf("%d\n",max);
	for(int i=0;i<cnt-1;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[cnt-1]);
	return 0;
}
