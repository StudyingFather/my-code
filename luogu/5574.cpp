// Problem : P5574 [CmdOI2019]任务分配问题
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P5574
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
using namespace std;
struct BIT
{
 int a[50005],n;
 void init(int N)
 {
  n=N;
 }
 int lowbit(int x)
 {
  return x&(-x);
 }
 void update(int x,int y)
 {
  while(x<=n)
  {
   a[x]+=y;
   x+=lowbit(x);
  }
 }
 int query(int x)
 {
  int ans=0;
  while(x)
  {
   ans+=a[x];
   x-=lowbit(x);
  }
  return ans;
 }
}tr;
int a[50005],f[50005],g[50005],sum;
int cl=1,cr=0,n,k;
void modify(int l,int r)
{
 while(cl<l)
 {
  tr.update(a[cl],-1);
  sum-=tr.query(a[cl]-1);
  cl++;
 }
 while(cl>l)
 {
  cl--;
  tr.update(a[cl],1);
  sum+=tr.query(a[cl]-1);
 }
 while(cr<r)
 {
  cr++;
  tr.update(a[cr],1);
  sum+=tr.query(n)-tr.query(a[cr]);
 }
 while(cr>r)
 {
  tr.update(a[cr],-1);
  sum-=tr.query(n)-tr.query(a[cr]);
  cr--;
 }
}
void dfs(int l1,int r1,int l2,int r2)
{
 if(l1>r1)return;
 int mid=(l1+r1)>>1,p=mid;
 for(int i=min(mid-1,r2);i>=l2;i--)
 {
  modify(i+1,mid);
  if(g[i]+sum<f[mid])
   f[mid]=g[i]+sum,p=i;
 }
 dfs(l1,mid-1,l2,p);
 dfs(mid+1,r1,p,r2);
}
int main()
{
 cin>>n>>k;
 tr.init(n);
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  a[i]=n+1-a[i];
  modify(1,i);
  f[i]=sum;
 }
 for(int i=2;i<=k;i++)
 {
  memcpy(g,f,sizeof(f));
  memset(f,63,sizeof(f));
  dfs(1,n,1,n);
 }
 cout<<f[n]<<endl;
 return 0;
}