/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][SRM][1] D
#       @file         :D.cpp
#       @date         :2014/07/10 19:34
#       @algorithm    :luan gao
******************************************************************************/

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int N, M, ans, cnt ;
string s;
int main()
{
	int i, j ;
	getline(cin, s);
	N = s.size();
	ans = N;
	for (i = 0, cnt = 0; i < N; i++)
		if (s[i] == 'n') cnt++;
	ans = min(ans, (cnt - 1) / 2);
	for (i = 0, cnt = 0; i < N; i++)
		if (s[i] == 'i') cnt++;
	ans = min(ans, cnt);
	for (i = 0, cnt = 0; i < N; i++)
		if (s[i] == 't') cnt++;
	ans = min(ans, cnt);
	for (i = 0, cnt = 0; i < N; i++)
		if (s[i] == 'e') cnt++;
	ans = min(ans, cnt / 3);
	cout << ans << endl;
	return 0 ;
}
