/*
 Name: luogu P2300
 Author: StudyingFather
 Date: 2019/10/30 10:15
 Website: https://studyingfather.com
*/
#include <cstdio>
long long s[200005],g[200005];
int a[200005],f[200005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  s[i]=s[i-1]+a[i];
 }
 for(int i=1;i<=n;i++)
 {
  int p=i-1;
  while(p>=0)
  {
   if(s[i]-s[p]>=g[p])break;
   p--;
  }
  f[i]=f[p]+i-p-1;
  g[i]=s[i]-s[p];
 }
 printf("%d\n",f[n]);
 return 0;
}