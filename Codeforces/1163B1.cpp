#include <cstdio>
#include <algorithm>
using namespace std;
int f[100005],t[100005];
int main()
{
 int n,maxf=0,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  f[t[x]]--;
  t[x]++;
  f[t[x]]++;
  maxf=max(maxf,t[x]);
  bool flag=false;
  if(f[1]==i||f[i]==1)flag=true;
  else if(f[1]==1&&f[maxf]*maxf==i-1)flag=true;
  else if(f[maxf-1]*(maxf-1)==i-maxf&&f[maxf]==1)flag=true;
  if(flag)ans=i;
 }
 printf("%d\n",ans);
 return 0;
}