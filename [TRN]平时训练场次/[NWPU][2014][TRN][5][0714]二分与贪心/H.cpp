/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][5] H
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][5][0714]二分与贪心\H.cpp
* @date         :2014/07/15 17:37
* @algorithm    :Binary Search
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

const int maxN = 2005;
int64 a[maxN];
int t, tt;
int n;

int64 Bsearch_lower_bound(int64 x)
{
	int64 l = 0, r = n - 1, mid = 0;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (a[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

int64 Bsearch_upper_bound(int64 x)
{
	int64 l = 0, r = n - 1, mid = 0;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (a[mid] <= x) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int64 cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int64 x = a[i] - a[j];
			int64 y = a[i] + a[j];
			int64 t1 = Bsearch_lower_bound(x + 1);
			int64 t2 = Bsearch_upper_bound(y - 1);
			cnt += (t2 - t1);
			if ((i >= t1) && (i <= t2)) cnt--;
			if ((j >= t1) && (j <= t2)) cnt--;
		}
	}
	printf("Case %d: %d\n", ++tt, cnt / 3);
}

int main()
{
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}