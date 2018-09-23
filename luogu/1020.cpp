//nlogn algorithm,200 points
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define maxn 100005
using namespace std;
int n,f[maxn],a[maxn],ans;
struct cmp
{
 bool operator()(int a,int b)
 {
  return a>b;
 }
};
int main()
{
 int n=1;
 while(~scanf("%d",&a[n]))
  n++;
 n--;
 f[1]=a[1],ans=1;
 for(int i=2;i<=n;i++)
  if(a[i]<=f[ans])f[++ans]=a[i];
  else f[upper_bound(f+1,f+ans+1,a[i],cmp())-f]=a[i];
 printf("%d\n",ans);
 memset(f,0,sizeof(f));
 f[1]=a[1],ans=1;
 for(int i=2;i<=n;i++)
  if(a[i]>f[ans])f[++ans]=a[i];
  else f[lower_bound(f+1,f+ans+1,a[i])-f]=a[i];
 printf("%d\n",ans);
 return 0;
}
