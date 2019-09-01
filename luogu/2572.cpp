/*
 Name: luogu P2572
 Author: StudyingFather
 Date: 2019/08/22 17:53
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
#include <set>
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
void revert(int l,int r)
{
 auto itr=split(r+1),itl=split(l);
 for(auto it=itl;it!=itr;it++)
  it->val=!it->val;
}
int query_tot(int l,int r)
{
 int ans=0;
 auto itr=split(r+1),itl=split(l);
 for(auto it=itl;it!=itr;it++)
  ans+=(it->val)*((it->r)-(it->l)+1);
 return ans;
}
int query_max(int l,int r)
{
 int ans=0,tmp=0;
 auto itr=split(r+1),itl=split(l);
 for(auto it=itl;it!=itr;it++)
  if(it->val==0)tmp=0;
  else
  {
   tmp+=(it->r)-(it->l)+1;
   ans=max(ans,tmp);
  }
 return ans;
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=0;i<n;i++)
 {
  int x;
  scanf("%d",&x);
  s.insert(node(i,i,x));
 }
 while(m--)
 {
  int op,x,y;
  scanf("%d%d%d",&op,&x,&y);
  if(op==0)assign(x,y,0);
  else if(op==1)assign(x,y,1);
  else if(op==2)revert(x,y);
  else if(op==3)printf("%d\n",query_tot(x,y));
  else printf("%d\n",query_max(x,y));
 }
 return 0;
}