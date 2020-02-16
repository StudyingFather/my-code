#include <iostream>
using namespace std;
int f[20000005];
int calc(int x)
{
 int cur=2,ans=0;
 while(x!=1)
 {
  if(x%cur==0)
  {
   ans++;
   while(x%cur==0)
    x/=cur;
  }
  cur++;
 }
 return ans;
}
int main()
{
 for(int i=1;i<=20000000;i++)
 {
  f[i]=calc(i);
  if(i>4&&f[i]==4&&f[i-1]==4&&f[i-2]==4&&f[i-3]==4)
  {
   cout<<i-3<<endl;
   return 0;
  }
 }
}