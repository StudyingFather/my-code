#include <stdio.h>
#include <string.h>
#define MOD 99991
int in[15],snow[100005][6],head[100005],next[100005];
int n,tot;
int h(int a[])
{
 int sum=0,mul=1;
 for(int i=0;i<6;i++)
 {
  sum=(sum+a[i])%MOD;
  mul=(long long)mul*a[i]%MOD;
 }
 return (sum+mul)%MOD;
}
bool equ(int a[],int b[])
{
 for(int i=0;i<6;i++)
  for(int j=0;j<6;j++)
  {
   int flag=1;
   for(int k=0;k<6;k++)
    if(a[(i+k)%6]!=b[(j+k)%6])flag=0;
   if(flag)return 1;
   flag=1;
   for(int k=0;k<6;k++)
    if(a[(i+k)%6]!=b[(j-k+6)%6])flag=0;
   if(flag)return 1;
  }
 return 0;
}
int insert(int a[])
{
 int v=h(a);
 for(int i=head[v];i;i=next[i])
  if(equ(snow[i],a))return 1;
 tot++;
 memcpy(snow[tot],a,6*sizeof(int));
 next[tot]=head[v];
 head[v]=tot;
 return 0;
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  for(int i=0;i<6;i++)
   scanf("%d",&in[i]);
  if(insert(in))
  {
   puts("Twin snowflakes found.");
   return 0;
  }
 }
 puts("No two snowflakes are alike.");
 return 0;
}
