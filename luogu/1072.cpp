#include <cstdio>
int gcd(int x,int y)
{
 return y==0?x:gcd(y,x%y);
}
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int a0,a1,b0,b1,ans=0;
  scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
  for(int i=1;i*i<=b1;i++)
   if(b1%i==0)
   {
    if(i%a1==0&&gcd(i/a1,a0/a1)==1&&gcd(b1/b0,b1/i)==1)ans++;
    int tmp=b1/i;
    if(tmp==i)continue;
    if(tmp%a1==0&&gcd(tmp/a1,a0/a1)==1&&gcd(b1/b0,b1/tmp)==1)ans++;
   }
  printf("%d\n",ans);
 }
 return 0;
}