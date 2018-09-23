#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct seg
{
 int l,r,num;
}c[1000005];
int s[1000005],a[1000005],cnt,maxlx=1,road[1000005];
long long minans=10000000000000;
int main()
{
 ios::sync_with_stdio(false);
 int n,m,k;
 cin>>n>>m>>k;
 int lx=0,segl=0;
 for(int i=1;i<=m;i++)
 {
  cin>>s[i];
  road[s[i]]++;
  if(s[i]==0)//起点被覆盖，直接无解 
  {
   cout<<-1;
   return 0;
  }
  if(road[s[i]-1])
  {
   lx++;
   maxlx=max(lx,maxlx);
   segl=s[i]+1;
  }
  else
  {
   lx=1;
   c[++cnt].l=segl;
   c[cnt].r=s[i]-1;
   segl=s[i]+1;
   c[cnt].num=c[cnt].r-c[cnt].l+1;
  }
  if(lx==k)//出现覆盖死角，无解 
  {
   cout<<-1;
   return 0;
  }
 }
 if(segl!=n)
 {
  c[++cnt].l=segl;
  c[cnt].r=n;
  c[cnt].num=c[cnt].r-c[cnt].l+1;
 }
 for(int i=1;i<=k;i++)
 {
  cin>>a[i];
  if(maxlx>=i)continue;
  int start=0;
  long long ans=0;
  for(int j=1;j<=cnt;j++)
  {
   int need=ceil((max(c[j].r-start+1,0))*1.0/i);
   ans+=need*a[i];
   int newstart=start+need*i;
   if(road[newstart])
   {
   	newstart=c[j].r+i;
   	ans+=a[i];
   }
   start=newstart;
   if(start==n+i)ans-=a[i];
  }
  minans=min(ans,minans);
 }
 cout<<minans;
 return 0;
}
