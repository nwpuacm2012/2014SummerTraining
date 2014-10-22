// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1306                                             *
*****************************************************************************/

#include <bits/stdc++.h>
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

inline int sign(int64 a)
{
    if (a == 0) return 0;
    return (a > 0)? 1: -1;
}

inline int64 ceil(int64 a, int64 b)
{
    int s = sign(a) * sign(b);
    return b / a + (b % a != 0 && s > 0);
}

inline int64 floor(int64 a, int64 b)
{
    int s = sign(a) * sign(b);
    return b / a - (b % a != 0 && s < 0);
}

int64 gcd_ex(int64 a, int64 b, int64& x, int64& y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    int64 d = gcd_ex(b, a % b, y, x);
    y = y - a / b * x;
    return d;
}

int t, tt;
int64 xl, xr; // x1, x2
int64 yl, yr; // y1, y2
int64 a, b, c;

void solve()
{
    int64 ans = 0;
    a = nextlld(); b = nextlld(); c = nextlld();
    xl = nextlld(); xr = nextlld();
    yl = nextlld(); yr = nextlld();
    if (a == 0 && b == 0)
    {
        ans = (c != 0)? 0: (xr - xl + 1) * (yr - yl + 1);
    }
    else if (a == 0)
    {
        if (c % b == 0)
        {
            int64 tmp = -c / b;
            if (yl <= tmp && tmp <= yr) ans = xr - xl + 1;
            else ans = 0;
        }
        else ans = 0;
    }
    else if (b == 0)
    {
        if (c % a == 0)
        {
            int64 tmp = -c / a;
            if (xl <= tmp && tmp <= xr) ans = yr - yl + 1;
            else ans = 0;
        }
        else ans = 0;
    }
    else
    {
        int64 r = 0, s = 0;
        int64 d = gcd_ex(a, b, r, s);
        a = -a;
        if (c % d == 0)
        {
            if (sign(d) * sign(b) < 0) swap(xl, xr);
            if (sign(d) * sign(a) < 0) swap(yl, yr);
            int64 xmin =  ceil(b, d * xl + c * r);
            int64 xmax = floor(b, d * xr + c * r);
            int64 ymin =  ceil(a, d * yl + c * s);
            int64 ymax = floor(a, d * yr + c * s);
            int64 amin = max(xmin, ymin);
            int64 amax = min(xmax, ymax);
            ans = (amin > amax)? 0: amax - amin + 1;
        }
        else ans = 0;

    }
    printf("Case %d: %lld\n", ++tt, ans);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
