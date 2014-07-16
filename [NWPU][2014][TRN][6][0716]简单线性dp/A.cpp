/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][6] A
* @file         :G:\My Source Code\¡¾ACM¡¿ÑµÁ·\[NWPU][2014][TRN][6][0716]¼òµ¥ÏßÐÔdp\A.cpp
* @date         :2014/07/16 10:58
* @algorithm    :DP
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1 : 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1 : 0; }

#include <map>
#include <vector>
#include <list>
#include <stack>
#include <deque>
#include <queue>

typedef long long int64;

int tt, s, i;
vector<int> a(100005), dp(100005);

void solve()
{
	int n = i + 1; dp[0] = 1;
	for (int j = 1; j < n; j++)
	{
		dp[j] = 1;
		for (int k = 0; k < j; k++)
		{
			if (a[j] < a[k] && dp[j] <= dp[k]) dp[j] = dp[k] + 1;
		}
	}
	int ans = 0;
	for (int j = 0; j < n; j++)
		updateMax(ans, dp[j]);
	printf("Test #%d:\n", ++tt);
	printf("  maximum possible interceptions: %d\n\n", ans);
}

int main()
{
	while (~scanf("%d", &s) && s != -1)
	{
		i = 0; a[0] = s;
		while (~scanf("%d", &s) && s != -1)
			a[++i] = s;
		solve();
	}
	return 0;
}
