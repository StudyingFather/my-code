#include <cstdio>
#include <algorithm>
using namespace std;
int my_pow(int a,int b)
{
 int ans=1;
 for(int i=1;i<=b;i++)
  ans*=a;
 return ans;
}
int change_to_10(int a,int b)
{
 int len=0,ans=0;
 while(a)
 {
  ans+=(a%10)*my_pow(b,len);
  a/=10;
  len++;
 }
 return ans;
}
int fen(int a)
{
 int ans=2;
 while(a)
 {
  ans=max(ans,a%10);
  a/=10;
 }
 return ans;
}
int find_min(int a,int b,int c)
{
 return max(fen(a),max(fen(b),fen(c)));
}
int main()
{
 int p,q,r,t;
 scanf("%d",&t);
 while(t--)
 {
  int flag=0;
  scanf("%d%d%d",&p,&q,&r);
  for(int i=find_min(p,q,r)+1;i<=16;i++)
   if(change_to_10(r,i)==change_to_10(p,i)*change_to_10(q,i))
   {
    printf("%d\n",i);
    flag=1;
    break;
   }
  if(!flag)printf("0\n");
 }
 return 0;
}
