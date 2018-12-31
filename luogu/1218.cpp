#include <stdio.h>
const int l[]={1,3,5,7,9};
int n;
bool is_prime(int num)
{
 if(num==1)return false;
 for(int i=2;i*i<=num;i++)
  if(num%i==0)return false;
 return true;
}
void dfs(int num,int d)
{
 if(d==n-1)
 {
  printf("%d\n",num);
  return;
 }
 for(int i=0;i<=4;i++)
  if(is_prime(10*num+l[i]))dfs(10*num+l[i],d+1);
}
int main()
{
 scanf("%d",&n);
 dfs(2,0);
 dfs(3,0);
 dfs(5,0);
 dfs(7,0);
 return 0;
}
