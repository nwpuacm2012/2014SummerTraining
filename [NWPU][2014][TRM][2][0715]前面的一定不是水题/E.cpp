#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const double pi = 3.1415926535898;
const double de = 0.000001;
int t, n, f;
double maxn;
double a[10100];
void init()
{
    int tmp;
    maxn = 0;
    scanf("%d%d", &n, &f);
    f++;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        a[i] = pi * tmp * tmp;
        if (a[i] > maxn) maxn = a[i];
    }

}
bool pan(double x)
{
    int cnt = 0;
    for (int i = 1 ;i <= n; i++)
    {
        if (a[i] < x) continue;
        cnt += int (a[i] / x);
    }
    if (cnt < f) return false;
    return true;
}
void deal()
{
    double re, mid, l = 0, r = maxn;
    while  (r - l >= de)
    {
        mid = (l + r) / 2;
        if (pan(mid))
        {
            re = mid;
            l = mid;
        }
            else r = mid;
    }
    printf("%.4f\n", re);

}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        init();
        deal();
    }
    return 0;
}