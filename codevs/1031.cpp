#include <stdio.h>
#include <math.h>
int a[20],used[20],n;
int is_prime(int num)
{
 for(int i=2;i<=sqrt(num);i++)
  if(num%i==0)return 0;
 return 1;
}
void print()
{
 for(int i=1;i<=n;i++)
  printf("%d ",a[i]);
 puts("");
 return;
}
void dfs(int d)
{
 if(d==n+1)
 {
  print();
  return;
 }
 for(int i=2;i<=n;i++)
  if(!used[i]&&is_prime(a[d-1]+i))
   if(d!=n||(d==n&&is_prime(a[1]+i)))
   {
    used[i]=1;
    a[d]=i;
    dfs(d+1);
    used[i]=0;
    a[d]=0;
   }
 return;
}
int main()
{
 scanf("%d",&n);
 a[1]=1;
 used[1]=1;
 dfs(2);
 return 0;
}
