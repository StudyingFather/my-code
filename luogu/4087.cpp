#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
struct entry
{
 int a,b,c;
}a[100005];
struct cow
{
 int id,g;
}c1[100005],c2[100005],c3[100005];
bool cmp1(const entry&a,const entry&b)
{
 return a.a<b.a;
}
bool cmp2(const cow&a,const cow&b)
{
 return a.g>b.g||(a.g==b.g&&a.id<b.id);
}
map<int,int> re;
int cnt,maxg,premaxg;
int main()
{
 int n,g,ans=0;
 scanf("%d%d",&n,&g);
 for(int i=1;i<=n;i++)
  scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
 sort(a+1,a+n+1,cmp1);
 for(int i=1;i<=n;i++)
 {
  if(!re[a[i].b])
  {
   re[a[i].b]=++cnt;
   c1[cnt].id=cnt;
  }
  c1[re[a[i].b]].g+=a[i].c;
  memcpy(c2,c1,sizeof(c1));
  sort(c2+1,c2+cnt+1,cmp2);
  maxg=c2[1].g;
  for(int j=1;;j++)
   if(c2[j].g!=maxg&&c3[j].g!=premaxg)break;//结果不变 
   else if(c2[j].g!=maxg&&c3[j].g==premaxg)
   {
   	ans++;
   	break;
   }
   else if(c2[j].g==maxg&&c3[j].g!=premaxg)
   {
    ans++;
    break;
   }
   //以上为第一名的数量改变
   else if(c2[j].id!=c3[j].id)//第一名id改变 
   {
   	ans++;
   	break;
   }
  premaxg=maxg;
  memcpy(c3,c2,sizeof(c2));//存放至上一次结果区 
 }
 printf("%d",ans);
 return 0;
}
