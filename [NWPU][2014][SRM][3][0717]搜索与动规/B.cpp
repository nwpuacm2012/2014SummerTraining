/**
 * @author neko01
 */
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
typedef long long LL;
#define INF 100000000
const double pi=acos(-1.0);
const double eqs=1e-10;
int a[355][355];
int dp[355][355];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            scanf("%d",&a[i][j]);
            if(i==1)
                dp[i][j]=a[i][j];
            else
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[n][i]);
    printf("%d\n",ans);
    return 0;
}