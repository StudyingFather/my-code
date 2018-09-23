#include <stdio.h>
const int pow_10[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int calc(int a)
{
 int ans=0;
 while(a)
 {
  a/=10;
  ans++;
 }
 return ans;
}
int fan(int a)
{
 int ans=0;
 while(a)
 {
  ans*=10;
  ans+=a%10;
  a/=10;
 }
 return ans;
}
int main()
{
 int k,p,ans=0;
 scanf("%d%d",&k,&p);
 for(int i=1;i<=k;i++)
 {
  int weishu=calc(i),num=i;
  num=num*pow_10[weishu]+fan(num);
  ans+=num;
  ans%=p;
 }
 printf("%d",ans);
 return 0;
}
