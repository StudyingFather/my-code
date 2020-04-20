#include <cstring>
#include <iostream>
using namespace std;
char s[5005],t[10005];
void init()
{
 t[0]=t[1]='#';
 int len=strlen(s);
 for(int i=0;i<len;i++)
 {
  t[2*i+2]=s[i];
  t[2*i+3]='#';
 }
 t[2*len+2]=0;
}
int main()
{
 int T;
 cin>>T;
 while(T--)
 {
  cin>>s;
  init();
  int len=strlen(t+1),l=1,r=len;
  while(l<=r)
  {
   if(t[l]==t[r])l++,r--;
   else break;
  }
  int ans=0,nl=l,nr=l;
  for(int i=l;i<=r;i++)
  {
   bool flag=true;
   for(int j=0;i-j>=l&&i+j<=r;j++)
    if(t[i-j]!=t[i+j])
    {
     flag=false;
     break;
    }
   if(flag)
   {
    if(ans<min(i-l+1,r-i+1))
    {
     ans=min(i-l+1,r-i+1);
     nl=max(l,i-ans);
     nr=min(r,i+ans);
    }
   }
  }
  if(l>r)
  {
   cout<<s<<endl;
   continue;
  }
  for(int i=1;i<l;i++)
   if(t[i]!='#')cout<<t[i];
  for(int i=nl;i<=nr;i++)
   if(t[i]!='#')cout<<t[i];
  for(int i=r+1;i<=len;i++)
   if(t[i]!='#')cout<<t[i];
  cout<<endl;
 }
 return 0;
}