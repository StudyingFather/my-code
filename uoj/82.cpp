#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef multiset<long long,greater<long long> > se;
se s;
long long t[25],n,m;
void dfs(int d,long long y)
{
 if(d==n+1)
 {
  s.insert(y);
  return;
 }
 for(long long i=0,num=1;i<=t[d];i++,num*=d)
  dfs(d+1,y*num);
}
int main()
{
 cin>>n>>m;
 for(int i=2;i<=n;i++)
 {
  int num=i;
  for(int j=2;j<=i;j++)
   while(num%j==0)
   {
    t[j]++;
    num/=j;
   }
 }
 dfs(1,1);
 for(se::iterator it=s.begin();it!=s.end();it++)
  if(m>=*it)
  {
   cout<<*it<<endl;
   m-=*it;
  }
 return 0;
}