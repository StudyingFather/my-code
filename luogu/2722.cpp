/*
 Name: luogu P2722
 Author: StudyingFather
 Date: 2019/08/24 15:40
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int c,w;
}a[10005];
int f[10005];
int main()
{
 int m,n;
 scanf("%d%d",&m,&n);
 for(int i=1;i<=n;i++)
  scanf("%d%d",&a[i].w,&a[i].c);
 for(int i=1;i<=n;i++)
  for(int j=a[i].c;j<=m;j++)
   f[j]=max(f[j],f[j-a[i].c]+a[i].w);
 printf("%d\n",f[m]);
 return 0;
}