/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][SRM][1] A
#       @file         :A.cpp
#       @date         :2014/07/10 19:58
#       @algorithm    :luan gao
******************************************************************************/

#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

char gird[2005][2005];
int n, m, k, res[2005];

void solve()
{
    memset(res, 0, sizeof(res));
    for (int i = 0; i < n; i++) scanf("%s", gird[i]);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (gird[i][j] == 'R' && i + j < m)
                res[i + j]++;
            else if (gird[i][j] == 'L' && j - i >= 0)
                res[j - i]++;
            else if (gird[i][j] == 'U' && i % 2 == 0)
                res[j]++;
        }
    }
    for (int i = 0; i < m; i++)
        printf("%d ", res[i]);
    puts("");
}

int main()
{
    while (~scanf("%d%d%d", &n, &m, &k)) solve();
    return 0;
}
