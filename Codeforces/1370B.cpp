// Problem : B. GCD Compression
// Contest : Codeforces - Codeforces Round #651 (Div. 2)
// URL : https://codeforces.com/contest/1370/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
using namespace std;
int a[2005],b[2005],res[2005],t[2005],n;
bool check(int p)
{
 memset(t,0,sizeof(t));
 memset(res,0,sizeof(res));
 int cnt=0;
 for(int i=1;i<=2*n;i++)
 {
  if(b[i]==0)
  {
   if(t[0])
    res[t[0]]=i,t[0]=0,cnt++;
   else
    t[0]=i;
  }
  else
  {
   int x=p-b[i];
   if(t[x])
    res[t[x]]=i,t[x]=0,cnt++;
   else
    t[x]=i;
  }
  if(cnt==n-1)
   return true;
 }
 return false;
}
void print()
{
 for(int i=1;i<=2*n;i++)
  if(res[i])
   cout<<i<<' '<<res[i]<<endl;
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(int i=1;i<=2*n;i++)
   cin>>a[i];
  for(int k=2;;k++)
  {
   for(int i=1;i<=2*n;i++)
    b[i]=a[i]%k;
   if(check(k))
   {
    print();
    break;
   }
  }
 }
 return 0;
}