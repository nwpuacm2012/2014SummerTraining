/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][6] B
* @file         :G:\My Source Code\¡¾ACM¡¿ÑµÁ·\[NWPU][2014][TRN][6][0716]¼òµ¥ÏßÐÔdp\B.cpp
* @date         :2014/07/16 11:46
* @algorithm    :DP
******************************************************************************/

//#define _CRT_SECURE_NO_WARNINGS
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

typedef long long int64;

const int MaxN = 105;
int n, a[MaxN][MaxN], dp[MaxN][MaxN];

void solve()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			int t1 = 0, t2 = 0;
			if (i - 1 >= 0) t1 = dp[i - 1][j];
			if (i - 1 >= 0 && j - 1 >= 0) t2 = dp[i - 1][j - 1];
			dp[i][j] = max(t1, t2) + a[i][j];
		}
	int ans = 0;
	for (int j = 0; j < n; j++)
		updateMax(ans, dp[n - 1][j]);
	printf("%d\n", ans);
}

int main()
{
	while (~scanf("%d", &n)) solve();
	return 0;
}
