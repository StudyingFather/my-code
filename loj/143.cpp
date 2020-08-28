// Problem : #143. 质数判定
// Contest : LibreOJ
// URL : https://loj.ac/problem/143
// Memory Limit : 256 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
const int p[]={2,3,5,7,17,19,61};
long long mul(long long x,long long y,long long p)
{
 long long ans=0;
 while(y)
 {
  if(y&1)ans=(ans+x)%p;
  x=(x+x)%p;
  y>>=1;
 }
 return ans;
}
long long fpow(long long x,long long y,long long p)
{
 long long ans=1;
 while(y)
 {
  if(y&1)ans=mul(ans,x,p);
  x=mul(x,x,p);
  y>>=1;
 }
 return ans;
}
bool millerRabin(long long x)
{
 if(x==2)return true;
 if(x%2==0||x==1)return false;
 long long w=x-1,cnt=0;
 while(w%2==0)
  w>>=1,cnt++;
 long long cur,pre;
 for(int i=0;i<7;i++)
 {
  if(x==p[i])return true;
  if(x%p[i]==0)return false;
  cur=fpow(p[i],w,x);
  for(int j=1;j<=cnt;j++)
  {
   pre=cur,cur=fpow(cur,2,x);
   if(cur==1&&pre!=1&&pre!=x-1)
    return false;
  }
  if(cur!=1)return false;
 }
 return true;
}
int main()
{
 long long x;
 while(cin>>x)
  cout<<(millerRabin(x)?"Y":"N")<<endl;
 return 0;
}