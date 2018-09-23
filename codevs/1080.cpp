#include<stdio.h>
int a[100001],n,m,sum[100001],c[100001];
int lowbit(int x)
{
 return x&(-x);  
}
int calc(int k)
{
 int tot=0;
 while(k>0)
 {
  tot+=c[k];
  k=k-lowbit(k);
 }    
 return tot;
}
void change(int i,int x)
{
 while(i<=n)
 {
  c[i]=c[i]+x;
  i=i+lowbit(i);
 }
}
int main()
{
 int i,k,t,s;
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  scanf("%d",&a[i]); 
  sum[i]=sum[i-1]+a[i];
 }
 for(i=1;i<=n;i++)
  c[i]=sum[i]-sum[i-lowbit(i)];
 scanf("%d",&m); 
 for(i=1;i<=m;i++)
 {
  scanf("%d",&k);
  if(k==1)
  {
   scanf("%d%d",&s,&t);
   change(s,t);
  }
  else 
  {
   scanf("%d%d",&s,&t);
   printf("%d\n",calc(t)-calc(s-1));
  }
 }
 return 0;
}
