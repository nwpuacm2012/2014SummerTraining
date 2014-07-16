#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>
#define MAXN 110
using namespace std;
int v, n;
int p[MAXN], m[MAXN], r[MAXN];

int cmp(const int a, const int b)
{
    return p[a] > p[b];
}
int main()
{
    //freopen("C:/Users/Admin/Desktop/in.txt", "r", stdin);

    while(cin >> v)
    {
        if(v == 0) return 0;

        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cin >> p[i] >> m[i];
        }

        for(int i = 0; i < n; i++) r[i] = i;

        sort(r, r+n, cmp);

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(v > m[r[i]])
            {
                ans += p[r[i]]*m[r[i]];
                v -= m[r[i]];
            }
            else
            {
                ans += v * p[r[i]];
                break;
            }
        }

        cout << ans << endl;

    }

    return 0;
}