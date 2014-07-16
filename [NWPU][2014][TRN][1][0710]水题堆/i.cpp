#include <iostream>
#include <algorithm>
using namespace std;
void fun(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
		cin>>A[i];
}
int main()
{
	int n,i,a,b;
	while(1)
	{
		cin>>n;
	if(n!=0)
	{
		int A[n],B[n];
		fun(A,n);fun(B,n);
		sort(A,A+n);sort(B,B+n);
		for(i=0,a=0,b=0;i<n;i++)
			{
			if(A[i]>B[i]) a+=2;
			if(A[i]==B[i]) a++,b++;
			if(A[i]<B[i]) b+=2;
			}
		cout << a <<" vs "<< b << endl;
	}
	else break;
	}
    return 0;
}