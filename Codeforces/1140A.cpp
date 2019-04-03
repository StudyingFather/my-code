#include <cstdio>
#include <algorithm>
using namespace std;
int a[10005];
int main()
{
 int n,ans=0,maxa=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  if(!maxa)maxa=a[i];
  maxa=max(a[i],maxa);
  if(i==maxa)
  {
   ans++;
   maxa=0;
  }
 }
 printf("%d\n",ans);
 return 0;
}