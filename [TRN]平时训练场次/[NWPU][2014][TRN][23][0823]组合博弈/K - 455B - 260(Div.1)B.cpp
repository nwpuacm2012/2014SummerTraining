// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :  #260 Div.1 B                                                 *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

const bool WIN  = true;
const bool LOSE = false;
const char aye[] = "Yes";
const char nay[] = "No";
const char ace[] = "Alice";
const char bob[] = "Bob";
const char fst[] = "First";
const char snd[] = "Second";

const int MaxN = 100005;

struct node
{
	int val, arr[30];
	node()
	{
		val = 0;
		memset(arr, 0, sizeof(arr));
	}
}trie[MaxN * 2];

int top = 1, len, n, k;
char str[MaxN];

inline int getNode() { return top++; }
inline void insert(int x, int d)
{
	if (d == len) return;
	int t = str[d] - 'a';
	if (trie[x].arr[t] == 0) trie[x].arr[t] = getNode();
	insert(trie[x].arr[t], d + 1);
}

int dfs(int x)
{
	int& ans = trie[x].val;
	ans = 0;
	bool flag = true;
	for (int i = 0; i < 26; i++) if (trie[x].arr[i])
	{
		flag = false;
		ans |= dfs(trie[x].arr[i]);
	}
	if (flag) ans = 1;
	return 3 - ans;
}

void solve()
{
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		len = strlen(str);
		insert(0, 0);
	}
	dfs(0);
	int ans = trie[0].val;
	if (ans < 2) puts(snd);
	else if (ans == 2)
		puts((k & 1)? fst: snd);
	else puts(fst);
}

int main()
{
	n = nextInt();
	k = nextInt();
	solve();
    return 0;
}
