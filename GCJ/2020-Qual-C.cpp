#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
 int s,t,id;
}a[1005];
char res[1005];
bool cmp(const node&a,const node&b)
{
 return a.s<b.s||(a.s==b.s&&a.t<b.t);
}
int main()
{
 int t;
 scanf("%d",&t);
 for(int kase=1;kase<=t;kase++)
 {
  memset(res,0,sizeof(res));
  int n,lastj=0,lastc=0;
  bool flag=true;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
   scanf("%d%d",&a[i].s,&a[i].t);
   a[i].id=i;
  }
  sort(a+1,a+n+1,cmp);
  printf("Case #%d: ",kase);
  for(int i=1;i<=n;i++)
   if(lastj<=a[i].s)
   {
    lastj=a[i].t;
    res[a[i].id]='J';
   }
   else if(lastc<=a[i].s)
   {
    lastc=a[i].t;
    res[a[i].id]='C';
   }
   else
   {
    flag=false;
    break;
   }
  if(flag)puts(res+1);
  else puts("IMPOSSIBLE");
 }
 return 0;
}