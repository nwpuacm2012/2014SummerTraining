/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRM][1] F
#       @file         :F.cpp
#       @date         :2014/07/13 20:00
#       @algorithm    :Binary Search
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n, mm[10005], num[10005];

bool search(int a, int b, int key)
{
    if (a > b) return 0;
    int mid = (a + b) / 2;
    if (mm[mid] == key) return 1;
    if (mm[mid] > key)
		return search(a, mid - 1, key);
    else
		return search(mid + 1, b, key);
}

void init()
{
	for (int i = 1; i <= 10000; i++)
		mm[i] = i * i;
	for (int i = 10000; i >= 1; i--)
    {
		for (int j = i - 1; j >= 1; j--)
		{
			int tt = i * i - j * j;
			if (tt > j * j) break;
			if (search(1, 10000, tt))
				num[i]++;
		}
	}
}

void solve()
{
    int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += num[i];
	printf("%d\n", sum);
}

int main()
{
    init();
    while (~scanf("%d",&n)) solve();
	return 0;
}
