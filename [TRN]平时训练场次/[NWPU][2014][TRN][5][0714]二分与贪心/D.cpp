/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][5] D
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][5][0714]二分与贪心\D.cpp
* @date         :2014/07/15 17:33
* @algorithm    :Binary Search
******************************************************************************/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, k;
double l, v[10005];
double maxa = 0;

bool test(int x)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += int(v[i] / x);
	return sum >= k;
}

int Bsearch(int l, int r)
{
	int res = 0;
	while (l <= r)
	{
		int mid = (r + l) / 2;
		if (test(mid))
			res = max(res, mid), l = mid + 1;
		else r = mid - 1;
	}
	return res;
}

void solve()
{
	maxa = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &l);
		l *= 100.0;
		v[i] = l;
		maxa = max(maxa, v[i]);
	}
	int ans = Bsearch(1, int(maxa));
	printf("%d.%02d\n", ans / 100, ans % 100);
}

int main()
{
	while (~scanf("%d%d", &n, &k))
		solve();
	return 0;
}