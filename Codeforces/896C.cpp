/*
 Name: Codeforces 896C
 Author: StudyingFather
 Date: 2019/08/01 08:06
 Website: https://studyingfather.com
*/
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define MOD 1000000007
using namespace std;
struct node
{
 int l,r;
 mutable long long val;
 node(int L,int R=-1,long long Val=0)
 {
  l=L,r=R,val=Val;
 }
 bool operator<(const node&a)const
 {
  return l<a.l;
 }
};
typedef pair<long long,int> pii;
set<node> odt;
long long a[100005],n,m,seed,vmax;
long long rnd()
{
 long long ret=seed;
 seed=(seed*7+13)%MOD;
 return ret;
}
set<node>::iterator split(int pos)
{
 auto it=odt.lower_bound(node(pos));
 if(it!=odt.end()&&it->l==pos)return it;
 it--;
 int l=it->l,r=it->r;
 long long val=it->val;
 odt.erase(it);
 odt.insert(node(l,pos-1,val));
 return odt.insert(node(pos,r,val)).first;
}
void assign(int l,int r,long long val)
{
 auto itr=split(r+1),itl=split(l);
 odt.erase(itl,itr);
 odt.insert(node(l,r,val));
}
long long fpow(long long x,long long y,long long mod)
{
 long long ans=1;
 x%=mod;
 while(y)
 {
  if(y&1)ans=ans*x%mod;
  x=x*x%mod;
  y>>=1;
 }
 return ans;
}
void add(int l,int r,long long val)
{
 auto itr=split(r+1),itl=split(l);
 for(auto it=itl;it!=itr;it++)
  it->val+=val;
}
long long kth(int l,int r,int k)
{
 vector<pii> a;
 auto itr=split(r+1),itl=split(l);
 for(auto it=itl;it!=itr;it++)
  a.push_back(pii(it->val,(it->r)-(it->l)+1));
 sort(a.begin(),a.end());
 for(auto it=a.begin();it!=a.end();it++)
 {
  k-=it->second;
  if(k<=0)return it->first;
 }
 return -1;
}
long long sum(int l,int r,int x,int y)
{
 long long ans=0;
 auto itr=split(r+1),itl=split(l);
 for(auto it=itl;it!=itr;it++)
  ans=(ans+fpow(it->val,x,y)*((it->r)-(it->l)+1))%y;
 return ans;
}
int main()
{
 cin>>n>>m>>seed>>vmax;
 for(int i=1;i<=n;i++)
 {
  a[i]=rnd()%vmax+1;
  odt.insert(node(i,i,a[i]));
 }
 for(int i=1;i<=m;i++)
 {
  int op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1,x,y;
  if(l>r)swap(l,r);
  if(op==3)x=rnd()%(r-l+1)+1;
  else x=rnd()%vmax+1;
  if(op==4)y=rnd()%vmax+1;
  if(op==1)add(l,r,x);
  else if(op==2)assign(l,r,x);
  else if(op==3)cout<<kth(l,r,x)<<endl;
  else cout<<sum(l,r,x,y)<<endl;
 }
 return 0;
}