/*
 Name: luogu P4979
 Author: StudyingFather
 Date: 2019/08/29 19:06
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
set<node> se;
char s[500005];
int n,k;
set<node>::iterator split(int pos)
{
 auto it=se.lower_bound(node(pos));
 if(it!=se.end()&&it->l==pos)return it;
 it--;
 int l=it->l,r=it->r,val=it->val;
 se.erase(it);
 se.insert(node(l,pos-1,val));
 return se.insert(node(pos,r,val)).first;
}
void assign(int l,int r,int val)
{
 auto itr=split(r+1),itl=split(l);
 se.erase(itl,itr);
 se.insert(node(l,r,val));
}
bool query(int l,int r)
{
 auto itr=split(r+1),itl=split(l);
 for(auto it=itl;it!=itr;it++)
  if(it->val!=itl->val)return false;
 if(l!=1&&r!=n)
 {
  itl--;
  return itl->val!=itr->val;
 }
 else return true;
}
int main()
{
 scanf("%d",&n);
 scanf("%s",s+1);
 for(int i=1;i<=n;i++)
  se.insert(node(i,i,s[i]-'A'));
 scanf("%d",&k);
 while(k--)
 {
  scanf("%s",s);
  if(s[0]=='A')
  {
   int x,y;
   scanf("%d%d",&x,&y);
   scanf("%s",s);
   assign(x,y,s[0]-'A');
  }
  else
  {
   int x,y;
   scanf("%d%d",&x,&y);
   puts(query(x,y)?"Yes":"No");
  }
 }
 return 0;
}