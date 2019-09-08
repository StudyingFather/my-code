/*
 Name: luogu P3740
 Author: StudyingFather
 Date: 2019/09/02 18:59
 Website: https://studyingfather.com
*/
#include <cstdio>
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
int t[1005];
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
int query()
{
 int ans=0;
 for(auto it=s.begin();it!=s.end();it++)
  if(it->val&&!t[it->val])t[it->val]++,ans++;
 return ans;
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 s.insert(node(1,n,0));
 for(int i=1;i<=m;i++)
 {
  int l,r;
  scanf("%d%d",&l,&r);
  assign(l,r,i);
 }
 printf("%d\n",query());
 return 0;
}