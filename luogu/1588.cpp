/*
 Name: luogu P1588
 Author: StudyingFather
 Date: 2019/09/06 19:06
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
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
char str[5];
int l,t,o;
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
 static int t[35];
 int ans=0;
 memset(t,0,sizeof(t));
 auto itr=split(r+1),itl=split(l);
 for(auto it=itl;it!=itr;it++)
  if(!t[it->val])ans++,t[it->val]++;
 return ans;
}
int main()
{
 scanf("%d%d%d",&l,&t,&o);
 s.insert(node(1,l,1));
 while(o--)
 {
  scanf("%s",str);
  if(str[0]=='C')
  {
   int a,b,c;
   scanf("%d%d%d",&a,&b,&c);
   if(a>b)swap(a,b);
   assign(a,b,c);
  }
  else
  {
   int a,b;
   scanf("%d%d",&a,&b);
   if(a>b)swap(a,b);
   printf("%d\n",query(a,b));
  }
 }
 return 0;
}