/*
 Name: Atcoder Beginner Contest 138B
 Author: StudyingFather
 Date: 2019/08/18 20:04
 Website: https://studyingfather.com
*/
#include <cstdio>
int main()
{
 int n;
 double ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  ans+=1.0/x;
 }
 printf("%.10lf\n",1/ans);
 return 0;
}