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
const int N=105;
char s1[N];
char s2[N];
int a[30],b[30];
int main()
{
    scanf("%s%s",s1,s2);
    int len1=strlen(s1);
    int len2=strlen(s2);
    for(int i=0;i<len1;i++)
        a[s1[i]-'a']++;
    for(int i=0;i<len2;i++)
        b[s2[i]-'a']++;
    for(int i=0;i<26;i++)
        if(a[i]<b[i])
        {
            puts("need tree");
            return 0;
        }
    int j=0;
    for(int i=0;i<len1;i++)
        if(j<len2&&s1[i]==s2[j])
            j++;
    if(j>=len2)
    {
        puts("automaton");
        return 0;
    }
    if(len1==len2)
        puts("array");
    else
        puts("both");
    return 0;
}