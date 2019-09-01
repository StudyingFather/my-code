/*
 Name: luogu P5514
 Author: StudyingFather
 Date: 2019/08/24 16:55
 Website: https://studyingfather.com
*/
#include <cstdio>
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 while(n--)
 {
  int x;
  scanf("%d",&x);
  ans^=x;
 }
 printf("%d\n",ans);
 return 0;
}