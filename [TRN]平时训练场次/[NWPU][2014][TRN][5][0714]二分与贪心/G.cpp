/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][5] G
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][5][0714]二分与贪心\G.cpp
* @date         :2014/07/15 17:37
* @algorithm    :Binary Search
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;
int a[maxN];
int t, tt;
int n, q, x, y;

int Bsearch_lower_bound(int x)
{
	int l = 0, r = n - 1, mid = 0;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (a[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

int Bsearch_upper_bound(int x)
{
	int l = 0, r = n - 1, mid = 0;
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
	scanf("%d%d", &n, &q);
	printf("Case %d:\n", ++tt);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &x, &y);
		int l = Bsearch_lower_bound(x);
		int r = Bsearch_upper_bound(y);
		printf("%d\n", r - l);
	}
}

int main()
{
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}