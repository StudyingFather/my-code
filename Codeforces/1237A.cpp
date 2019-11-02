/*
 Name: Codeforces 1237A
 Author: StudyingFather
 Date: 2019/10/17 13:50
 Website: https://studyingfather.com
*/
#include <cstdio>
int main()
{
 int n;
 scanf("%d",&n);
 int f=1;
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  if(x%2==0)printf("%d\n",x/2);
  else printf("%d\n",(x+f)/2),f*=-1;
 }
 return 0;
}