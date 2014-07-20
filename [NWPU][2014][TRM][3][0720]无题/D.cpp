/**
 * @author neko01
 */
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define INF 0x7fffffff
const double eps=1e-8;
const double pi=acos(-1.0);
const int N=1005;
LL sum1[N],sum2[N],a[N][N];
LL f1[N*N],f2[N*N];
int main()
{
    int n,m,k,p;
    cin>>n>>m>>k>>p;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    priority_queue<LL>row;
    priority_queue<LL>col;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum1[i]+=a[i][j];
        }
        row.push(sum1[i]);
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            sum2[j]+=a[i][j];
        }
        col.push(sum2[j]);
    }
    for(int i=1;i<=k;i++)
    {
        LL maxRow=row.top();
        row.pop();
        f1[i]=f1[i-1]+maxRow;
        row.push(maxRow-p*m);
    }
    for(int i=1;i<=k;i++)
    {
        LL maxCol=col.top();
        col.pop();
        f2[i]=f2[i-1]+maxCol;
        col.push(maxCol-p*n);
    }
    LL ans=f1[k]+f2[0];
    for(int i=0;i<k;i++)
        ans=max(ans,f1[i]+f2[k-i]-(LL)i*(k-i)*p);
    cout<<ans<<endl;
    return 0;
}