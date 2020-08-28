// Problem : E. Binary Subsequence Rotation
// Contest : Codeforces - Codeforces Round #651 (Div. 2)
// URL : https://codeforces.com/contest/1370/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s,t;
int a[1000005],n;
int calc(int op)
{
 int sum=0,ans=0;
 for(int i=0;i<n;i++)
 {
  sum+=a[i]*op;
  ans=max(ans,sum);
  if(sum<0)
   sum=0;
 }
 return ans;
}
int main()
{
 cin>>n;
 cin>>s>>t;
 for(int i=0;i<n;i++)
 {
  if(s[i]==t[i])a[i]=0;
  else if(s[i]=='1')a[i]=1;
  else a[i]=-1;
 }
 int sum=0;
 for(int i=0;i<n;i++)
  sum+=a[i];
 if(sum!=0)
  cout<<-1<<endl;
 else
  cout<<max(calc(1),calc(-1))<<endl;
 return 0;
}