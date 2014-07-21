#include <iostream>
#include <algorithm>
#define  DBG 0
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t-->0)
	{
	int n,i,x,m;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(i=0;i<n;i++) DBG&&cout<<a[i]<<" ";
	DBG&&cout<<endl;
	for(x=a[0],i=0,m=1;i<n;i++)
	{
		if(a[i]!=x)  m++,x=a[i];
	}
    cout << 10*a[n-1]+5*m+n << endl;
	}
    return 0;
}