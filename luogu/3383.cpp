#include <stdio.h>
int is_pr[10000005];
int n,m;
void get_prime()
{
 for(int i=2;i<=n;i++)
  is_pr[i]=1;
 for(long long i=2;i<=n;i++)
 {
  if(is_pr[i])
   for(long long j=i*i;j<=n;j+=i)
    is_pr[j]=0;
 }
}
int main()
{
 scanf("%d%d",&n,&m);
 get_prime();
 for(int i=1;i<=m;i++)
 {
  int num;
  scanf("%d",&num);
  if(is_pr[num])puts("Yes");
  else puts("No");
 }
 return 0;
}
