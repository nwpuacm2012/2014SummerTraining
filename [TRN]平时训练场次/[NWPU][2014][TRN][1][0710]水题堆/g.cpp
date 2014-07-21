#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
	int m,n,i;
	while(1)
	{
		cin>>n>>m;
		if(m==0&&n==0) break;
		int A[n];
		for(i=0;i<n;i++) scanf("%d",&A[i]);
		sort(A,A+n);
		if(m>n) m=n;
		for(i=n-1;i>=n-m+1;i--) printf("%d ",A[i]);
		printf("%d",A[i]);
		cout<<endl;
	}
    return 0;
}