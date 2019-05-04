#include <cstdio>
int a[105];
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=2;i<=n;i++)
  if(a[i-1]==1)
  {
   if(a[i]==3)ans+=4;
   else if(a[i-2]==3)ans+=2;
   else ans+=3;
  }
  else if(a[i-1]==2)
  {
   if(a[i]==1)ans+=3;
   else
   {
    puts("Infinite");
    return 0;
   }
  }
  else
  {
   if(a[i]==1)ans+=4;
   else
   {
    puts("Infinite");
    return 0;
   }
  }
 puts("Finite");
 printf("%d\n",ans);
 return 0;
}