#include <cstdio>
#include <algorithm>
using namespace std;
int ma[1005];
int main()
{
 int n,x0,ans=1005;
 scanf("%d%d",&n,&x0);
 for(int i=1;i<=n;i++)
 {
  int a,b;
  scanf("%d%d",&a,&b);
  if(a>b)swap(a,b);
  for(int j=a;j<=b;j++)
   ma[j]++;
 }
 for(int i=0;i<=1000;i++)
  if(ma[i]==n)ans=min(ans,abs(i-x0));
 if(ans==1005)printf("-1\n");
 else printf("%d\n",ans);
 return 0;
}