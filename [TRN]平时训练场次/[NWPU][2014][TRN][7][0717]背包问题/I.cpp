/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][7] I
* @file         :G:\My Source Code\°æACM°ø—µ¡∑\[NWPU][2014][TRN][7][0717]±≥∞¸Œ Ã‚\I.cpp
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

const int MaxN = 100005;
int v[MaxN], w[MaxN], dp[MaxN];
int n, V;

void solve()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) scanf("%d%d", &w[i], &v[i]);
    for (int i = 0; i < n; i++)
        for (int j = V; j >= w[i]; j--)
            updateMax(dp[j], dp[j - w[i]] + v[i]);
    printf("%d\n", dp[V]);
}

int main()
{
	while (~scanf("%d%d", &n, &V)) solve();
	return 0;
}

