//A
//每读一个判断一遍，能排好就直接排好，不行的情况先判断有环，输入到最后一个数据才能得出有多种情况
#include <cstdio>
#include <cstring>

int map[30][30];
int in[30];
int ans[30];

int chk(int n)//0:none  1:ok  2:mul
{
	
	int f1,f2,t;
	memset(in,0,sizeof(in));
	memset(ans,-1,sizeof(ans));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			in[i]+=map[j][i];
		}
	}
	f2=0;
	for(int i=0;i<n;i++)
	{

		t=0;
		f1=0;
		for(int j=0;j<n;j++)
		{
			if(in[j]==0)
			{
				f1+=1;
				t=j;
			}
		}
		if(f1==0)
		{
			return 0;
		}
		if(f1>1)
		{
			f2=1;
			in[t]--;
			for(int j=0;j<n;j++)
			{
				if(map[t][j]==1)
					in[j]--;
			}
			continue;
		}
		ans[i]=t;
		in[t]--;
		for(int j=0;j<n;j++)
		{
			if(map[t][j]==1)
				in[j]--;
		}
	}
	if(f2==1)
		return 2;
	return 1;
}

int main()
{
	int n,m,t,f;
	char s[10];
	while(scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0)
			break;
		memset(map,0,sizeof(map));
		f=0;
		for(int i=0;i<m;i++)
		{
			scanf("%s",s);
			if(f==1)
			{
				continue;
			}
			
			map[s[0]-'A'][s[2]-'A']=1;
			t=chk(n);
			
			if(t==0)
			{
				f=1;
				printf("Inconsistency found after %d relations.\n",i+1);
				continue;
			}
			if(t==1)
			{
				f=1;
				printf("Sorted sequence determined after %d relations: ",i+1);
				for(int k=0;k<n;k++)
				{
					printf("%c",ans[k]+'A');
				}
				printf(".\n");
				continue;
			}
		}
		
		if(f==0)
		{
			printf("Sorted sequence cannot be determined.\n");
		}
	}
	return 0;
}
