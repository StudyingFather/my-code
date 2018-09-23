#include <cstdio>
#include <algorithm>
using namespace std;
int c[5005],cnt;
int main()
{
 int n,s,h,a,b,ans=0;
 scanf("%d%d",&n,&s);
 scanf("%d%d",&a,&b);
 h=a+b;
 for(int i=1;i<=n;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  if(h>=x)c[++cnt]=y;
 }
 sort(c+1,c+cnt+1);
 for(int i=1;i<=cnt;i++)
  if(s>=c[i])s-=c[i],ans++;
  else break;
 printf("%d",ans);
 return 0;
}
