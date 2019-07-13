#include <cstdio>
#include <algorithm>
int a[1000005],que[1000005],f[1000005];
int main()
{
 int n,q;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 scanf("%d",&q);
 while(q--)
 {
  int x,h,t37;
  scanf("%d",&x);
  h=t37=1,que[1]=1;
  for(int i=2;i<=n;i++)
  {
   while(h<=t37&&i-que[h]>x)
    h++;
   if(a[que[h]]>a[i])f[i]=f[que[h]];
   else f[i]=f[que[h]]+1;
   while(h<=t37&&(f[que[t37]]>f[i]||(f[que[t37]]==f[i]&&a[que[t37]]<=a[i])))
    t37--;
   que[++t37]=i;
  }
  printf("%d\n",f[n]);
 }
 return 0;
}