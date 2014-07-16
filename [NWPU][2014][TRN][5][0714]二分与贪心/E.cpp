/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][5] E
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][5][0714]二分与贪心\E.cpp
* @date         :2014/07/15 17:35
* @algorithm    :Binary Search
******************************************************************************/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, k;
int l, v[50005];
int maxa = 0;

bool test(int x)
{
	int sum = 0, st = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		if (v[i] - v[st] <= x)
			sum++;
		else
			st = i;
	}
	//printf("\t%s with x = %d, result is that sum = %d.\n", __func__, x, sum);
	return sum <= k;
}

int Bsearch(int l, int r)
{
	int res = r;
	while (l <= r)
	{
		int mid = (r + l) / 2;
		//printf("l = %d, r = %d, mid = %d, res = %d.\n", l, r, mid, res);
		if (test(mid))
			l = mid + 1;
		else
			res = min(res, mid), r = mid - 1;
	}
	return res;
}

void solve()
{
	maxa = l;
	v[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &l);
		v[i] = l;
	}
	v[n + 1] = maxa;
	sort(v, v + n + 2);
	int ans = Bsearch(0, maxa);
	printf("%d\n", ans);
}

int main()
{
	while (~scanf("%d%d%d", &l, &n, &k))
		solve();
	return 0;
}