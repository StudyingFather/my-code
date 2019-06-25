#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long ans,f[300005][2];
char s[300005];
int main()
{
 ios::sync_with_stdio(false);
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>s;
  int len=strlen(s),brl=0,brr=0;
  for(int i=0;i<len;i++)
   if(s[i]=='(')brl++;
   else
   {
    if(brl)brl--;
    else brr++;
   }
  if(!(brr&&brl))
  {
   if(brr)f[brr][1]++;
   else f[brl][0]++;
  }
 }
 ans+=f[0][0]*f[0][0];
 for(int i=1;i<=300000;i++)
  ans+=f[i][0]*f[i][1];
 cout<<ans;
 return 0;
}
