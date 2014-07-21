#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int bi[10010],pi[10010];
int biu[10010];
int n,ct,mi[110];

int main()
{
	int cnt;
	cin>>cnt;
	while(cnt--) {
		cin>>n;
		ct = 0;
		for(int i=0;i<n;i++) {
			cin>>mi[i];
			for(int j=0;j<mi[i];j++) {
				cin>>bi[ct]>>pi[ct];
				biu[ct]=bi[ct];
				ct++;
			}
		}
		sort(biu,biu+ct);
		int nb = unique(biu,biu+ct) - biu;
		// for(int i=0;i<nb;i++)
		// 	cout<<biu[i]<<" ";
		//cout<<endl;
		double ans = 0;
		for(int i=0;i<nb;i++) {
			int tt = 0,tsum=0;
			int cb = biu[i];
			bool done = 1;
			for(int j=0;j<n;j++) {
				int tmin = INT_MAX;
				for(int k=0;k<mi[j];k++) {
					if(bi[tt] >= cb && pi[tt] < tmin) 
						tmin = pi[tt];
					tt++;
				}
				if(tmin == INT_MAX) {
					done = 0;
					break;
				}
				else
					tsum += tmin;
			}
			if(done) {
				//cout<<cb<<" "<<tsum<<endl;
				ans = max(ans,double(cb)/double(tsum));
			}
		}
		printf("%.3f\n",round(ans*1000)/1000);
	}
}