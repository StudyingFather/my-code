#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int cmp(int a,int b)
{
 return a>b;
}
int a[1005];
int main()
{
 int t;
 scanf("%d",&t);
 for(int i=1;i<=t;i++)
 {
  int s,f,need;
  memset(a,0,sizeof(a));
  printf("Scenario #%d:\n",i);
  scanf("%d%d",&s,&f);
  need=s;
  for(int i=1;i<=f;i++)
   scanf("%d",&a[i]);
  sort(a+1,a+f+1,cmp);
  for(int i=1;i<=f;i++)
  {
   need-=a[i];
   if(need<=0)
   {
   	printf("%d\n",i);
   	break;
   }
  }
  if(need>0)printf("impossible\n");
  puts("");
 }
 return 0;
}
