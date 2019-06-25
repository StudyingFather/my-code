#include <cstdio>
#include <algorithm>
using namespace std;
int b[105];
int cmp(int a,int b)
{
 return a>b;
}
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
  scanf("%d",&b[i]);
 sort(b+1,b+n+1,cmp);
 for(int i=1;i<=n;i++)
  if(k%b[i]==0)
  {
   printf("%d",k/b[i]);
   return 0;
  }
}
