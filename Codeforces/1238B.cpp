/*
 Name: Codeforces 1238B
 Author: StudyingFather
 Date: 2019/09/25 22:45
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int a[100005];
int main()
{
 int q;
 scanf("%d",&q);
 while(q--)
 {
  int n,r,ans=0;
  scanf("%d%d",&n,&r);
  for(int i=1;i<=n;i++)
   scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  int m=unique(a+1,a+n+1)-(a+1);
  for(int i=1;i<=m;i++)
   ans=max(ans,min((int)ceil(1.0*a[i]/r),m-i+1));
  printf("%d\n",ans);
 }
 return 0;
}