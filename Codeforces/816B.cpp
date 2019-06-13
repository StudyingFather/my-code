#include <cstdio>
int a[300005];
int main()
{
 int n,k,q;
 scanf("%d%d%d",&n,&k,&q);
 for(int i=1;i<=n;i++)
 {
  int l,r;
  scanf("%d%d",&l,&r);
  a[l]++,a[r+1]--;
 }
 for(int i=1;i<=300000;i++)
  a[i]+=a[i-1];
 for(int i=1;i<=300000;i++)
  if(a[i]>=k)a[i]=1;
  else a[i]=0;
 for(int i=1;i<=300000;i++)
  a[i]+=a[i-1];
 for(int i=1;i<=q;i++)
 {
  int l,r;
  scanf("%d%d",&l,&r);
  printf("%d\n",a[r]-a[l-1]);
 }
 return 0;
}