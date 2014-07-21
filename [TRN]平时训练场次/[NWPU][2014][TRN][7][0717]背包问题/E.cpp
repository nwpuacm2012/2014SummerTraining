/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][7] E
* @file         :G:\My Source Code\°æACM°ø—µ¡∑\[NWPU][2014][TRN][7][0717]±≥∞¸Œ Ã‚\E.cpp
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

const int MaxN = 10005;
const double eps = 1e-8;
int t, n, v[MaxN];
double P, p[MaxN], dp[MaxN];
void solve()
{
    scanf("%lf%d", &P, &n); P = 1.0 - P;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%lf", &v[i], &p[i]);
        p[i] = 1.0 - p[i]; sum += v[i];
    }
    /* WA */// for (int i = 1; i < n; i++) dp[i] = 0.0;
    /* AC */   memset(dp, 0, sizeof(dp));
    dp[0] = 1.0;
    for (int i = 0; i < n; i++)
        for (int j = sum; j >= v[i]; j--)
            updateMax(dp[j], dp[j - v[i]] * p[i]);
    for (int i = sum; i >= 0; i--)
        if (dp[i] - P > eps)
    {
        printf("%d\n", i); break;
    }
}

int main()
{
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
