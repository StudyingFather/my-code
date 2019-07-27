#include <iostream>
#include <algorithm>
using namespace std;
struct seg
{
 int x,y;
}s[150005];
int f[3000005],n,maxx;
bool cmp(const seg&a,const seg&b)
{
 return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int main()
{
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>s[i].x>>s[i].y;
  maxx=max(maxx,s[i].y);
 }
 sort(s+1,s+n+1,cmp);
 int ans=0,t=1;
 for(int i=0;i<=maxx;i++)
 {
  if(i)f[i]=max(f[i],f[i-1]);
  while(s[t].x==i&&t<=n)
  {
   f[s[t].y]=max(f[s[t].y],f[s[t].x-1]+s[t].y-s[t].x+1);
   t++;
  }
  ans=max(ans,f[i]);
 }
 cout<<ans<<endl;
 return 0;
}