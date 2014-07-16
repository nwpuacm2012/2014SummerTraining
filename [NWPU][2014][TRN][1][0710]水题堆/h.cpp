#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
char a1[20];
char b1[20];
char a[12];
char b[12];
long long aa,bb;
int l1,l2;
int main()
{
      char c;
      int ii,jj,i,j;
      while(scanf("%s%s",&a1,&b1)!=EOF){
        memset(a,'0',sizeof(a));
        memset(b,'0',sizeof(b));
          l1=strlen(a1);
          l2=strlen(b1);
          for(i=0,ii=0;i<l1;i++){
            if(a1[i]!=',')
               a[ii++]=a1[i];
             }
             a[ii++]='\0';
          for(i=0,ii=0;i<l2;i++)
            if(b1[i]!=',')
               b[ii++]=b1[i];
               b[ii++]='\0';
        aa=atoi(a);
        bb=atoi(b);
        cout<<aa+bb<<endl;
        }
       return 0;
}