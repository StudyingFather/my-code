#include<stdio.h>
#include<algorithm>
using namespace std;
struct player
{
 int num,s,w;
}a[200000],win[100000],lose[100000];
bool cmp(const player&a,const player&b)
{
 return a.s>b.s||(a.s==b.s&&a.num<b.num);
}
int main()
{
 int n,r,q;
 scanf("%d%d%d",&n,&r,&q);
 n*=2;
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i].s);
  a[i].num=i;
 }
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i].w);
 sort(a+1,a+n+1,cmp);
 for(int i=0;i<r;i++)
 {
  for(int j=1;j<=n/2;j++)
   if(a[j*2].w>a[j*2-1].w)
   {
    a[j*2].s++;
    win[j]=a[j*2];
    lose[j]=a[j*2-1];
   }
   else 
   {
    a[j*2-1].s++;
    win[j]=a[j*2-1];
    lose[j]=a[j*2];
   }
  merge(win+1,win+n/2+1,lose+1,lose+n/2+1,a+1,cmp);
 }
 printf("%d",a[q].num);
 return 0;
}
