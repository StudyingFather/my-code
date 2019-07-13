#include <cstdio>
#include <algorithm>
using namespace std;
int l[1000005],r[1000005],q[1000005];
int main()
{
 int n,h=0,t=0,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d%d",&l[i],&r[i]);
 q[1]=1;
 for(int i=1;i<=n;i++)
 {
  while(l[q[h]]>r[i]&&h<=t)
   h++;
  if(h<=t)ans=max(ans,i-q[h]+1);
  int tmp=i;
  while(l[i]>l[q[t]]&&h<=t)
   tmp=q[t--];
  l[tmp]=l[i],q[++t]=tmp;
 }
 printf("%d\n",ans);
 return 0;
}