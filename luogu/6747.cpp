// Problem: P6747 Teleport
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6747
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int t[65][2];
long long minc[65];
int main()
{
 ios::sync_with_stdio(false);
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  for(int i=30;i>=0;i--)
   t[i][((x>>i)&1)^1]++;
 }
 minc[0]=min(t[0][0],t[0][1]);
 for(int i=31;i<=50;i++)
  t[i][1]=n;
 for(int i=1;i<=50;i++)
  minc[i]=minc[i-1]+(1ll<<i)*min(t[i][0],t[i][1]);
 int q;
 cin>>q;
 while(q--)
 {
  long long m;
  cin>>m;
  if(m<minc[50])
  {
   cout<<-1<<endl;
   continue;
  }
  long long ans=0;
  for(int i=50;i>=0;i--)
   if(m>=(__int128)(1ll<<i)*t[i][1]+(i>0?minc[i-1]:0))
    ans+=(1ll<<i),m-=(1ll<<i)*t[i][1];
   else
    m-=(1ll<<i)*t[i][0];
  cout<<ans<<endl;
 }
 return 0;
}