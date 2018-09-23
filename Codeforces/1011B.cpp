#include <cstdio>
#include <algorithm>
using namespace std;
int a[105],n,m,t[105],cnt;
bool cmp(int a,int b)
{
 return a>b;
}
int main()
{
 scanf("%d%d",&n,&m);
 if(n>m)
 {
  printf("0");
  return 0;
 }
 for(int i=1;i<=m;i++)
 {
  scanf("%d",&a[i]);
  t[a[i]]++;
  if(t[a[i]]==1)cnt++;
 }
 sort(t,t+101,cmp);
 for(int i=100;i>0;i--)
 {
  int num=0;
  for(int j=0;j<=cnt;j++)
   num+=t[j]/i;
  if(num>=n)
  {
   printf("%d",i);
   return 0;
  }
 }
}
