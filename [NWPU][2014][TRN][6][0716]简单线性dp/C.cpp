/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][6] C
* @file         :G:\My Source Code\¡¾ACM¡¿ÑµÁ·\[NWPU][2014][TRN][6][0716]¼òµ¥ÏßÐÔdp\C.cpp
* @date         :2014/07/16 11:59
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
const int MaxL = 1005;
string a, b;
int dp[MaxL][MaxL];

void solve()
{
    int n = a.size(), m = b.size();
    int tmp = max(n, m);
    for (int i = 0; i <= tmp; i++)
        dp[i][0] = dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        dp[i][j] = 0;
        if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
        else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }
    int ans = dp[n][m];
    printf("%d\n", ans);
}

int main()
{
    while (cin >> a >> b) solve();
    return 0;
}
