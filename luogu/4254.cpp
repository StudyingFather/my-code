// Problem : P4254 [JSOI2008]Blue Mary开公司
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P4254
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <string>
#define MAXT 50005
using namespace std;
struct project
{
 double s,p;
}pro[100005];
int s[200005];
int cnt;
double calc(int id,int d)
{
 return pro[id].s+pro[id].p*(d-1);
}
void update(int root,int l,int r,int u)
{
 int v=s[root],mid=(l+r)>>1;
 int ls=root<<1,rs=root<<1|1;
 if(l==r)
 {
  if(calc(u,mid)>calc(v,mid))s[root]=u;
  return;
 }
 if(pro[v].p<pro[u].p)
 {
  if(calc(u,mid)>calc(v,mid))
  {
   s[root]=u;
   update(ls,l,mid,v);
  }
  else
   update(rs,mid+1,r,u);
 }
 else if(pro[v].p>pro[u].p)
 {
  if(calc(u,mid)>calc(v,mid))
  {
   s[root]=u;
   update(rs,mid+1,r,v);
  }
  else
   update(ls,l,mid,u);
 }
 else
 {
  if(pro[u].s>pro[v].s)s[root]=u;
 }
}
double query(int root,int l,int r,int d)
{
 if(r<d||d<l)return 0;
 int mid=(l+r)>>1;
 double res=calc(s[root],d);
 if(l==r)return res;
 return max(res,max(query(root<<1,l,mid,d),query(root<<1|1,mid+1,r,d)));
}
int main()
{
 int n;
 cin>>n;
 while(n--)
 {
  string op;
  cin>>op;
  if(op=="Project")
  {
   cnt++;
   cin>>pro[cnt].s>>pro[cnt].p;
   update(1,1,MAXT,cnt);
  }
  else
  {
   int d;
   cin>>d;
   cout<<(int)query(1,1,MAXT,d)/100<<endl;
  }
 }
 return 0;
}