//最长回文字串+01滚动
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[5002];
int n;
int f[2][5001];

int main()
{
	int maxl=0;
	scanf("%d",&n);
	scanf("%s",str+1);
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(str[i]==str[n-j+1])
					f[i%2][j]=f[(i-1)%2][j-1]+1;
				else
					f[i%2][j]=max(f[(i-1)%2][j],f[i%2][j-1]);

			if(maxl<f[i%2][j])
				maxl=f[i%2][j];

		}
	}

	printf("%d\n",n-maxl);
	return 0;
}

