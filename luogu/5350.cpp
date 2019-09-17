/*
 Name: luogu P5350
 Author: StudyingFather
 Date: 2019/09/17 21:12
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#define MOD 1000000007
using namespace std;
struct node
{
 int l,r;
 mutable int val;
 node(int L=0,int R=-1,int Val=0)
 {
  l=L,r=R,val=Val;
 }
 bool operator<(const node&a)const
 {
  return l<a.l;
 }
};
set<node> s;
set<node>::iterator split(int pos)
{
 auto it=s.lower_bound(node(pos));
 if(it!=s.end()&&it->l==pos)return it;
 it--;
 int l=it->l,r=it->r,val=it->val;
 s.erase(it);
 s.insert(node(l,pos-1,val));
 return s.insert(node(pos,r,val)).first;
}
void assign(int l,int r,int val)
{
 auto itr=split(r+1),itl=split(l);
 s.erase(itl,itr);
 s.insert(node(l,r,val));
}
int query(int l,int r)
{
 int ans=0;
 auto itr=split(r+1),itl=split(l);
 for(auto it=itl;it!=itr;it++)
  ans=(ans+((it->r)-(it->l)+1ll)*it->val)%MOD;
 return ans;
}
void add(int l,int r,int val)
{
 auto itr=split(r+1),itl=split(l);
 for(auto it=itl;it!=itr;it++)
  it->val=(it->val+val)%MOD;
}
void copy(int l1,int r1,int l2,int r2)
{
 int d=l2-l1;
 vector<node> v;
 auto itr=split(r1+1),itl=split(l1);
 for(auto it=itl;it!=itr;it++)
  v.push_back(node(it->l+d,it->r+d,it->val));
 itr=split(r2+1),itl=split(l2);
 s.erase(itl,itr);
 for(auto it=v.begin();it!=v.end();it++)
  s.insert(*it);
}
void swap(int l1,int r1,int l2,int r2)
{
 if(l1>l2)swap(l1,l2),swap(r1,r2);
 int d=l2-l1;
 vector<node> v;
 auto itr=split(r1+1),itl=split(l1);
 for(auto it=itl;it!=itr;it++)
  v.push_back(node(it->l+d,it->r+d,it->val));
 s.erase(itl,itr);
 itr=split(r2+1),itl=split(l2);
 for(auto it=itl;it!=itr;it++)
  v.push_back(node(it->l-d,it->r-d,it->val));
 s.erase(itl,itr);
 for(auto it=v.begin();it!=v.end();it++)
  s.insert(*it);
}
void reverse(int l,int r)
{
 auto itr=split(r+1),itl=split(l);
 vector<node> v;
 for(auto it=itl;it!=itr;it++)
  v.push_back(node(r-(it->r)+l,r-(it->l)+l,it->val));
 s.erase(itl,itr);
 for(auto it=v.begin();it!=v.end();it++)
  s.insert(*it);
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  s.insert(node(i,i,x));
 }
 while(m--)
 {
  int op;
  scanf("%d",&op);
  if(op==1)
  {
   int l,r;
   scanf("%d%d",&l,&r);
   printf("%d\n",query(l,r));
  }
  else if(op==2)
  {
   int l,r,val;
   scanf("%d%d%d",&l,&r,&val);
   assign(l,r,val);
  }
  else if(op==3)
  {
   int l,r,val;
   scanf("%d%d%d",&l,&r,&val);
   add(l,r,val);
  }
  else if(op==4)
  {
   int l1,r1,l2,r2;
   scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
   copy(l1,r1,l2,r2);
  }
  else if(op==5)
  {
   int l1,r1,l2,r2;
   scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
   swap(l1,r1,l2,r2);
  }
  else
  {
   int l,r;
   scanf("%d%d",&l,&r);
   reverse(l,r);
  }
 }
 for(auto it=s.begin();it!=s.end();it++)
  for(int i=it->l;i<=it->r;i++)
   printf("%d ",it->val);
 return 0;
}