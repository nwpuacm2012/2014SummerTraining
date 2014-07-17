#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int c, g;
long long f[30000][20];
int w[200], l[200]; 
int main()
{
	memset(f, 0, sizeof(0));
	scanf("%d%d", &c, &g);
	for (int i = 1; i <= c; i++)
		scanf("%d", &l[i]);
	for (int i = 1; i <= g; i++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 1;i <= c; i++)
	{
		f[l[i] * w[1] + 10000][1]++;
	}
	
	for (int i = 2; i <= g; i++)
	{
		for (int j = 1; j <= c; j++)
		for (int k = -7500; k <= 7500; k++)
		{
			int t = k + 10000;
			if (f[t][i - 1] != 0)
			f[t + w[i] * l[j]][i] += f[t][i - 1]; 
		}
	}
	printf("%d\n", f[10000][g]);
	return 0;
}