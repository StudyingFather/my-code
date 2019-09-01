/*
 Name: luogu P2787
 Author: StudyingFather
 Date: 2019/08/13 19:24
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
struct node
{
 int l,r,val;
 node(int L,int R=-1,int Val=0)
 {
  l=L,r=R,val=Val;
 }
 bool operator<(const node&a)const
 {
  return l<a.l;
 }
};
char s[50005];
set<node> se;
set<node>::iterator split(int pos)
{
 auto it=se.lower_bound(pos);
 if(it!=se.end()&&it->l==pos)return it;
 it--;
 int l=it->l,r=it->r,val=it->val;
 se.erase(it);
 se.insert(node(l,pos-1,val));
 return se.insert(node(pos,r,val)).first;
}
void assign(int l,int r,int x)
{
 auto itr=split(r+1),itl=split(l);
 se.erase(itl,itr);
 se.insert(node(l,r,x));
}
int query(int l,int r,int x)
{
 auto itr=split(r+1),itl=split(l);
 int ans=0;
 for(auto it=itl;it!=itr;it++)
  if(it->val==x)ans+=(it->r)-(it->l)+1;
 return ans;
}
void strsort(int l,int r)
{
 auto itr=split(r+1),itl=split(l);
 static int t[35];
 memset(t,0,sizeof(t));
 for(auto it=itl;it!=itr;it++)
  t[it->val]+=(it->r)-(it->l)+1;
 se.erase(itl,itr);
 int cur=l;
 for(int i=0;i<26;i++)
  if(t[i])
  {
   se.insert(node(cur,cur+t[i]-1,i));
   cur+=t[i];
  }
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 scanf("%s",s+1);
 for(int i=1;i<=n;i++)
  se.insert(node(i,i,s[i]-'a'>=0?s[i]-'a':s[i]-'A'));
 while(m--)
 {
  int op,x,y;
  scanf("%d%d%d",&op,&x,&y);
  if(op==1)
  {
   scanf("%s",s);
   printf("%d\n",query(x,y,s[0]-'a'>=0?s[0]-'a':s[0]-'A'));
  }
  else if(op==2)
  {
   scanf("%s",s);
   assign(x,y,s[0]-'a'>=0?s[0]-'a':s[0]-'A');
  }
  else strsort(x,y);
 }
 return 0;
}