#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
int l[300005],r[300005],a[300005],t[300005],m,n,cnt;
stack<int> s;
bool check()
{
 for(int i=1;i<=m;i++)
 {
  if(l[a[i]]==i)
  {
   if(r[a[i]]!=i)s.push(a[i]);
  }
  else
  {
   if(s.top()!=a[i])return false;
   if(r[a[i]]==i)s.pop();
  }
 }
 return true;
}
int main()
{
 memset(l,63,sizeof(l));
 cin>>m>>n;
 for(int i=1;i<=m;i++)
 {
  cin>>a[i];
  if(!t[a[i]])cnt++,t[a[i]]=1;
  l[a[i]]=min(l[a[i]],i);
 }
 for(int i=m;i;i--)
  r[a[i]]=max(r[a[i]],i);
 if(!check())cout<<-1<<endl;
 else
 {
  cout<<cnt<<endl;
  for(int i=1;i<=m;i++)
   if(l[a[i]]==i)cout<<a[i]<<' '<<l[a[i]]<<' '<<r[a[i]]<<endl;
 }
 return 0;
}