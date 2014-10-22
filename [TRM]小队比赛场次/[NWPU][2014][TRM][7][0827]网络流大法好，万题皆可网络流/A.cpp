// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   A                                                        *
*****************************************************************************/

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

const int MaxN = 1005;
const int MaxL = 16;

const int f[MaxL] = {
    1, 2, 3, 5, 8, 13, 21, 34, 55,
    89, 144, 233, 377, 610, 987, 1597
};

int sg[MaxN]; bool h[MaxL];
int n, m, l;

void SG()
{
    for (int i = 1; i < MaxN; i++)
    {
        fill(h, h + 16, 0);
        for (int j = 0; j < MaxL; j++)
        {
            if (i < f[j]) break;
            h[sg[i - f[j]]] = 1;
        }
        for (int j = 0; j < MaxL; j++) if (!h[j])
        {
            sg[i] = j;
            break;
        }
    }
}

void solve()
{
    if (sg[n] ^ sg[m] ^ sg[l])
        puts("Fibo");
    else
        puts("Nacci");
}

int main()
{
    SG();
    while (~scanf("%d%d%d", &n, &m, &l) && m)
        solve();
    return 0;
}
