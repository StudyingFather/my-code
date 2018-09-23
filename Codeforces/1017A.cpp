#include <cstdio>
#include <algorithm>
using namespace std;
struct stu
{
 int score,id;
}s[1005];
bool cmp(const stu&a,const stu&b)
{
 return a.score>b.score||(a.score==b.score&&a.id<b.id);
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int a,b,c,d;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  s[i].score=a+b+c+d;
  s[i].id=i;
 }
 sort(s+1,s+n+1,cmp);
 for(int i=1;i<=n;i++)
  if(s[i].id==1)
  {
   printf("%d",i);
   return 0;
  }
}
