/*
 Name: loj 6284
 Author: StudyingFather
 Date: 2019/08/22 11:22
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
struct node
{
 int l,r,val;
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
 if(it->l==pos)return it;
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
int query(int l,int r,int val)
{
 int ans=0;
 auto itr=split(r+1),itl=split(l);
 for(auto it=itl;it!=itr;it++)
  ans+=((it->val)==val)*((it->r)-(it->l)+1);
 return ans;
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  s.insert(node(i,i,x));
 }
 for(int i=1;i<=n;i++)
 {
  int l,r,x;
  scanf("%d%d%d",&l,&r,&x);
  printf("%d\n",query(l,r,x));
  assign(l,r,x);
 }
 return 0;
}