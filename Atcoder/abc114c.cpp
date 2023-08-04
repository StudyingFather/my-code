#include <stdio.h>
#include <string.h>
int a[15],t[3];
int main()
{
 int n,ans=1;
 scanf("%d",&n);
 if(n<357)
 {
  puts("0");
  return 0;
 }
 memset(a,-1,sizeof(a));
 a[1]=2,a[2]=1,a[3]=0;
 while(1)
 {
  memset(t,0,sizeof(t));
  a[1]++;
  int cur=1,num=0;
  while(a[cur]>=3)
   a[cur]=0,a[++cur]++;
  while(a[cur]>=0)
   cur++;
  cur--;
  if(cur>=10)break;
  for(int i=cur;i>=1;i--)
  {
   num*=10;
   if(a[i]==0)num+=3,t[0]++;
   else if(a[i]==1)num+=5,t[1]++;
   else num+=7,t[2]++;
  }
  if(num>n)break;
  else if(t[0]&&t[1]&&t[2])ans++;
 }
 printf("%d\n",ans);
 return 0;
}
