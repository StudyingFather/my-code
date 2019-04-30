#include <iostream>
using namespace std;
char s[1000005];
long long f[105];
int main()
{
 int q;
 cin>>s;
 f[0]=f[1]=1;
 f[2]=2;
 for(int i=3;i<=91;i++)
  f[i]=f[i-1]+f[i-2];
 cin>>q;
 while(q--)
 {
  long long l,r,ans=0;
  cin>>l>>r;
  l--;
  for(int i=91;i;i--)
  {
   if(l>=f[i]&&r>=f[i])l-=f[i],r-=f[i];
   else if(l>=f[i])l-=f[i],ans-=f[i-1];
   else if(r>=f[i])r-=f[i],ans+=f[i-1];
  }
  cout<<ans<<endl;
 }
 return 0;
}