/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRM][1] E
#       @file         :E.cpp
#       @date         :2014/07/13 20:00
#       @algorithm    :Hash
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int number[10001];
int tt, n, q;

void solve()
{
    v.clear();
    memset(number, 0, sizeof(number));
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        if(number[v[i]] == 0) number[v[i]] = i + 1;
    while (q--)
	{
        int t; cin >> t;
        if (number[t] == 0) cout << t << " not found" << endl;
        else cout << t << " found at " << number[t] << endl;
    }
}

int main()
{
    while (cin >> n >> q && n && q)
	{
        cout << "CASE# " << ++tt << ":\n";
        solve();
    }
    return 0;
}
