#include <cstdio>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;
struct node
{
 int l,r;
 bool operator <(const node&a)const
 {
  return r<a.l;
 }
};
set<node> se;
char s[5];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%s",s);
  if(s[0]=='A')
  {
   int l,r,cnt=0;
   scanf("%d%d",&l,&r);
   node x={l,r};
   set<node>::iterator it=se.find(x);
   while(it!=se.end())
   {
    se.erase(it);
    cnt++;
    it=se.find(x);
   }
   se.insert(x);
   printf("%d\n",cnt);
  }
  else printf("%d\n",se.size());
 }
 return 0;
}