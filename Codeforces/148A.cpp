#include <stdio.h>
int k,l,m,n,d,a[100005],ans=0;
void make(int x)
{
 for(int i=1;i*x<=d;i++)
  if(!a[i*x])
  {
   a[i*x]=1;
   ans++;
  }
}
int main()
{
 scanf("%d%d%d%d%d",&k,&l,&m,&n,&d);
 make(k);
 make(l);
 make(m);
 make(n);
 printf("%d",ans);
 return 0;
}
