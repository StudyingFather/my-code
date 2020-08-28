// Problem : #3253. 「JOI 2020 Final」JJOOII 2
// Contest : LibreOJ
// URL : https://loj.ac/problem/3253
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstdio>
#include <algorithm>
using namespace std;
char s[200005];
int a[200005],b[200005],c[200005];
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 scanf("%s",s+1);
 int ans=n+1;
 for(int i=1;i<=n;i++)
 {
  a[i]=a[i-1]+(s[i]=='J');
  b[i]=b[i-1]+(s[i]=='O');
  c[i]=c[i-1]+(s[i]=='I');
 }
 for(int i=1;i<=n;i++)
 {
  int p=lower_bound(a+i,a+n+1,a[i-1]+k)-a;
  if(p==n+1)continue;
  int q=lower_bound(b+p+1,b+n+1,b[p]+k)-b;
  if(q==n+1)continue;
  int r=lower_bound(c+q+1,c+n+1,c[q]+k)-c;
  if(r==n+1)continue;
  ans=min(ans,r-i+1-3*k);
 }
 printf("%d\n",ans==n+1?-1:ans);
 return 0;
}