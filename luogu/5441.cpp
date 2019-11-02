/*
 Name: luogu P5441
 Author: StudyingFather
 Date: 2019/10/23 23:45
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
int a[105];
int main()
{
 int n;
 scanf("%d",&n);
 if(n==1)
 {
  puts("0\n0");
  return 0;
 }
 printf("%d\n",n*(n-3)*(n*n+6*n-31)/48);
 for(int i=1;i<=n;i++)
 {
  memset(a,0,sizeof(a));
  for(int j=1;j<=(n+1)/2;j++)
   a[(i+j-1)%n+1]=1;
  for(int j=1;j<=n;j++)
   printf("%d ",a[j]);
  puts("");
 }
 return 0;
}