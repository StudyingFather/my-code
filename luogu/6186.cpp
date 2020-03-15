#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
struct BIT
{
 long long a[200005];
 int lowbit(int x)
 {
  return x&(-x);
 }
 void init()
 {
  memset(a,0,sizeof(a));
 }
 void add(int x,int y)
 {
  if(x==0)return;
  while(x<=n)
  {
   a[x]+=y;
   x+=lowbit(x);
  }
 }
 long long query(int x)
 {
  long long ans=0;
  while(x)
  {
   ans+=a[x];
   x-=lowbit(x);
  }
  return ans;
 }
}tr1,tr2;
int a[200005],b[200005];
int main()
{
 cin>>n>>m;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  b[i]=tr1.query(n)-tr1.query(a[i]);
  tr1.add(a[i],1);
 }
 tr1.init();
 for(int i=1;i<=n;i++)
  tr1.add(b[i],1),tr2.add(b[i],b[i]);
 while(m--)
 {
  int op,x;
  cin>>op>>x;
  if(op==1)
  {
   if(a[x]>a[x+1])
   {
    tr1.add(b[x+1],-1),tr2.add(b[x+1],-b[x+1]);
    b[x+1]--;
    tr1.add(b[x+1],1),tr2.add(b[x+1],b[x+1]);
   }
   else
   {
    tr1.add(b[x],-1),tr2.add(b[x],-b[x]);
    b[x]++;
    tr1.add(b[x],1),tr2.add(b[x],b[x]);
   }
   swap(a[x],a[x+1]),swap(b[x],b[x+1]);
  }
  else
  {
   if(x>=n)cout<<0<<endl;
   else
   {
    long long res1=(tr1.query(n)-tr1.query(x))*x;
    long long res2=tr2.query(n)-tr2.query(x);
    cout<<res2-res1<<endl;
   }
  }
 }
 return 0;
}