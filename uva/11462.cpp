#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int num,n,age[105],maxn,flag=1;
int main()
{
 while(1)
 {
  flag=1;
  memset(age,0,sizeof(age));
  scanf("%d",&n);
  if(n==0)return 0;
  for(int i=1;i<=n;i++)
  {
   scanf("%d",&num);
   age[num]++;
   if(num>=maxn)maxn=num;
  }
  for(int i=1;i<=maxn;i++)
   while(age[i]--)
    if(flag)
    {
     printf("%d",i);
     flag=0;
    }
    else printf(" %d",i);
  printf("\n");
 }
 return 0;
}
