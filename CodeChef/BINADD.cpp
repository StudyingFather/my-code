#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
 ios::sync_with_stdio(false);
 int t;
 cin>>t;
 while(t--)
 {
  string s,t;
  cin>>s>>t;
  bitset<100005> a(s),b(t),u,v;
  if(b.none())cout<<0<<endl;
  else
  {
   int ans=1;
   u=a^b;
   v=a&b;
   //cout<<u.to_string()<<' '<<v.to_string()<<endl;
   int len=max(s.length(),t.length());
   int s=-1;
   for(int i=0;i<=len;i++)
   {
    if(u[i]==0&&v[i]==1)
    {
     if(s==-1)s=i;
     else
     {
      ans=max(i-s+1,ans);
      s=i;
     }
    }
    if(u[i]==0&&v[i]==0&&s!=-1)
    {
     ans=max(i-s+1,ans);
     s=-1;
    }
   }
   cout<<ans<<endl;
  }
 }
 return 0;
}