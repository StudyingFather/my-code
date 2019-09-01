/*
 Name: Codeforces 915E
 Author: StudyingFather
 Date: 2019/08/22 16:48
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
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
int ans;
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
 for(auto it=itl;it!=itr;it++)
  if(it->val==2)ans-=((it->r)-(it->l)+1);
 s.erase(itl,itr);
 s.insert(node(l,r,val));
 ans+=(val==2)*(r-l+1);
}
int main()
{
 int n,q;
 scanf("%d%d",&n,&q);
 s.insert(node(1,n,2));
 ans=n;
 for(int i=1;i<=q;i++)
 {
  int l,r,x;
  scanf("%d%d%d",&l,&r,&x);
  assign(l,r,x);
  printf("%d\n",ans);
 }
 return 0;
}