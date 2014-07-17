/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][7] G
* @file         :G:\My Source Code\°æACM°ø—µ¡∑\[NWPU][2014][TRN][7][0717]±≥∞¸Œ Ã‚\G.cpp
* @date         :2014/07/17 10:54
* @algorithm    :Package
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

const int MaxN = 50005;
int dp[MaxN], c[11], w[11];
int t, n, v, y;

void solve()
{
    scanf("%d%d%d", &v, &y, &n);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) scanf("%d%d", &c[i], &w[i]), c[i] /= 1000;
    int res = v;
    while (y--)
    {
        v /= 1000;
        for (int i = 0; i < n; i++)
            for (int j = c[i]; j <= v; j++)
                updateMax(dp[j], dp[j - c[i]] + w[i]);
        res += dp[v]; v = res;
    }
    printf("%d\n", v);
}

int main()
{
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
