#include <cstdio>
#include <iostream>
#include <algorithm>
#define MOD 19260817
using namespace std;
long long a[105];
int res[1000005],cnt,n,m;
long long read()
{
 long long num=0,flag=1;
 char ch=getchar();
 while(ch<'0'||ch>'9')
 {
  if(ch=='-')flag=-1;
  ch=getchar();
 }
 while(ch>='0'&&ch<='9')
 {
  num=((num*10)+(ch-'0'))%MOD;
  ch=getchar();
 }
 return flag*num;
}
inline long long calc(int x)
{
 long long ans=0;
 for(int i=n;i;i--)
  ans=(ans+a[i])*x%MOD;
 ans=(ans+a[0])%MOD;
 return ans;
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=0;i<=n;i++)
  a[i]=read();
 for(int i=1;i<=m;i++)
  if(!calc(i))res[++cnt]=i;
 printf("%d\n",cnt);
 for(int i=1;i<=cnt;i++)
  printf("%d\n",res[i]);
 return 0;
}