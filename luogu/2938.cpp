/*
 Name: luogu P2938
 Author: StudyingFather
 Date: 2019/08/23 20:37
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[55][15],f[500005];
int main()
{
 int s,d,m;
 scanf("%d%d%d",&s,&d,&m);
 for(int i=1;i<=s;i++)
  for(int j=1;j<=d;j++)
   scanf("%d",&a[i][j]);
 for(int i=1;i<d;i++)
 {
  int maxv=0,rem=m;
  memset(f,0,sizeof(f));
  for(int j=1;j<=s;j++)
   if(a[j][i+1]>a[j][i])
    for(int k=a[j][i];k<=m;k++)
    {
     f[k]=max(f[k],f[k-a[j][i]]+a[j][i+1]);
     if(f[k]+m-k>=maxv+rem)maxv=f[k],rem=m-k;
    }
  m=maxv+rem;
 }
 printf("%d\n",m);
 return 0;
}