#include <stdio.h>
int a[100005],b[100005],t[100005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<n;i++)
  scanf("%d",&b[i]);
 for(int i=0;i<=3;i++)
 {
  bool flag=true;
  t[0]=i;
  for(int j=1;j<n;j++)
  {
   t[j]=a[j]+b[j]-t[j-1];
   if((t[j-1]|t[j])!=a[j]||(t[j-1]&t[j])!=b[j])
   {
    flag=false;
    break;
   }
  }
  if(flag)
  {
   puts("YES");
   for(int i=0;i<n;i++)
    printf("%d ",t[i]);
   return 0;
  }
 }
 puts("NO");
 return 0;
}
