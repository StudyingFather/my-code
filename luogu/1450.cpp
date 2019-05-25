#include <iostream>
#include <algorithm>
using namespace std;
long long c[5],d[5],f[100005],t,s;
int main()
{
 for(int i=1;i<=4;i++)
  cin>>c[i];
 cin>>t;
 f[0]=1;
 for(int i=1;i<=4;i++)
  for(int j=c[i];j<=100000;j++)
   f[j]+=f[j-c[i]];
 while(t--)
 {
  for(int i=1;i<=4;i++)
   cin>>d[i];
  cin>>s;
  long long ans=f[s];
  for(int i=1;i<=15;i++)
  {
   int x=s,tmp=i,cur=1,cnt=0;
   while(tmp)
   {
    if(tmp&1)x-=(d[cur]+1)*c[cur],cnt++;
    cur++;
    tmp>>=1;
   }
   if(x>=0)ans+=(cnt&1)?-f[x]:f[x];
  }
  cout<<ans<<endl;
 }
 return 0;
}