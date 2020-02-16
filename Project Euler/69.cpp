#include <cstdio>
#define MAXN 1000000
struct frac
{
 long long x,y;
 frac(int X,int Y)
 {
  x=X,y=Y;
 }
 bool operator<(const frac&a)const
 {
  return x*a.y<y*a.x;
 }
};
int phi[1000005];
int main()
{
 phi[1]=1;
 for(int i=2;i<=MAXN;i++)
  if(!phi[i])
  {
   for(int j=i;j<=MAXN;j+=i)
   {
    if(!phi[j])phi[j]=j;
    phi[j]=phi[j]/i*(i-1);
   }
  }
 int ans=1;
 frac maxp(1,1);
 for(int i=1;i<=MAXN;i++)
  if(maxp<frac(i,phi[i]))
  {
   maxp=frac(i,phi[i]);
   ans=i;
  }
 printf("%d\n",ans);
 return 0;
}