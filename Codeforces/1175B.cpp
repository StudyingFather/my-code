#include <iostream>
using namespace std;
struct operation
{
 char s[5];
 unsigned x;
}o[100005];
unsigned sta[100005],t,mul=1,flag;
int main()
{
 ios::sync_with_stdio(false);
 unsigned l,x=0;
 cin>>l;
 for(int i=1;i<=l;i++)
 {
  cin>>o[i].s;
  if(o[i].s[0]=='f')cin>>o[i].x;
 }
 for(int i=1;i<=l;i++)
 {
  if(o[i].s[0]=='a')
  {
   if(flag||x+mul!=(long long)x+mul)
   {
    cout<<"OVERFLOW!!!"<<endl;
    return 0;
   }
   x+=mul;
  }
  else if(o[i].s[0]=='f')
  {
   sta[t++]=o[i].x;
   if(mul*o[i].x==(long long)mul*o[i].x)mul*=o[i].x;
   else flag=t;
  }
  else
  {
   t--;
   if(flag>t)flag=0;
   else if(!flag)mul/=sta[t];
  }
 }
 cout<<x<<endl;
 return 0;
}