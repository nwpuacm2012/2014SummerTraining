/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][5] C
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][5][0714]二分与贪心\C.cpp
* @date         :2014/07/15 17:27
* @algorithm    :Binary Search
******************************************************************************/

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;

const int MaxN = 100005;
int64 data[MaxN];
int64 n, k;

bool test(int val)
{
	int64 cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (data[i] > val)
		{
			cnt += (data[i] - val + k - 2) / (k - 1);
			if (cnt > val)
				return true;
		}
	}
	return false;
}

int64 Bsearch(int64 l, int64 r)
{
	while (l < r)
	{
		int64 mid = l + (r - l) / 2;
		if (test(mid))
			l = mid + 1;
		else
			r = mid;
	}
	return l + (r - l) / 2;
}

void solve()
{
	int64 maxd = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &data[i]);
		maxd = max(data[i], maxd);
	}
	scanf("%lld", &k);
	if (k == 1)
		printf("%lld\n", maxd);
	else
		printf("%d\n", Bsearch(1LL, maxd));
}

int main()
{
	while (scanf("%lld", &n) != EOF)
		solve();
	return 0;
}