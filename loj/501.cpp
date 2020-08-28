// Problem: #501. 「LibreOJ β Round」ZQC 的树列
// Contest: LibreOJ
// URL: https://loj.ac/problem/501
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int a[5005],cnt=2;
bool dfs(long long x,int p)
{
 if(x==1)return true;
 int cnt0=cnt;
 for(int i=2;i<=60;i++)
  if(x%((1ll<<i)-1)==0)
  {
   for(int j=1;j<=i;j++)
    a[++cnt]=p;
   if(dfs(x/((1ll<<i)-1),p^1))return true;
   cnt=cnt0;
  }
 return false;
}
int main()
{
 long long k;
 cin>>k;
 a[1]=1,a[2]=2;
 while(k%2==0)
 {
  k/=2;
  cnt++;
  a[cnt]=cnt;
 }
 if(!dfs(k,0))cout<<"qnq"<<endl;
 else
 {
  cout<<cnt<<endl;
  for(int i=1;i<=cnt;i++)
   cout<<a[i]<<' ';
 }
 return 0;
}