#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[25005],f[25005];
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  memset(f,0,sizeof(f));
  int n,ans=0;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
   scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  f[0]=1;
  for(int i=1;i<=n;i++)
  {
   if(!f[a[i]])ans++;
   for(int j=a[i];j<=a[n];j++)
    if(f[j-a[i]])f[j]=1;
  }
  printf("%d\n",ans);
 }
 return 0;
}