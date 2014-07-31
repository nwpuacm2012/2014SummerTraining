//E
//求环，Floyd求出两种货币间相互兑换获得的最大值，再枚举所有货币，如有一种再次兑换到自己是变多了就输出YES
//输入数据用map建立string与int的关系
#include <iostream>
#include <string>
#include <map>
#include <cstring>

using namespace std;

map<string,int> dict;

double map1[35][35];

int n;

void floyd()
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(map1[i][j]<map1[i][k]*map1[k][j])
				{
					map1[i][j]=map1[i][k]*map1[k][j];
				}
			}
		}
	}
}

int main()
{
	int m;
	string str,str2;
	double d;
	int t1,t2;
	int iii=0;
	while(cin>>n)
	{
		iii++;
		if(n==0)
		{
			break;
		}
		for(int i=0;i<n;i++)
		{
			cin>>str;
			dict.insert(pair<string,int>(str,i));
		}
		memset(map1,0,sizeof(map1));
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>str>>d>>str2;
			t1=dict.find(str)->second;
			t2=dict.find(str2)->second;
			map1[t1][t2]=d;
		}
		floyd();

		str="No";
		for(int i=0;i<n;i++)
		{
			if(map1[i][i]>1)
			{
				str="Yes";
			}
		}
		cout<<"Case "<<iii<<": "<<str<<endl;
	}
}
