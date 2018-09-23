#include <stdio.h>
#include <string.h>
int a[105],b[105];
void pow_2(int n)
{
 b[1]=1;
 b[0]=1;
 for(int i=1;i<=n;i++)
  for(int j=b[0];j>=1;j--)
  {
   b[j]*=2;
   if(b[j]>=10)
   {
    b[j+1]++;
    b[j]%=10;
    if(j==b[0])b[0]++;
   }
  }
}
void plas()
{
 for(int i=1;i<=a[0];i++)
 {
  a[i]+=b[i];
  if(a[i]>=10)
  {
   a[i+1]++;
   a[i]%=10;
   if(i==a[0])a[0]++;
  }
 }
}
int main()
{
 int n;
 scanf("%d",&n);
 a[0]=1;
 for(int i=1;i<=n;i++)
 {
  memset(b,0,sizeof(b));
  pow_2(i);
  plas();
 }
 for(int i=a[0];i>=1;i--)
  printf("%d",a[i]);
 return 0;
}
