/*
 Name: Atcoder Beginner Contest 141C
 Author: StudyingFather
 Date: 2019/08/18 20:12
 Website: https://studyingfather.com
*/
#include <cstdio>
int a[100005];
int main()
{
 int n,k,q;
 scanf("%d%d%d",&n,&k,&q);
 for(int i=1;i<=q;i++)
 {
  int x;
  scanf("%d",&x);
  a[x]++;
 }
 for(int i=1;i<=n;i++)
  puts(k-q+a[i]>0?"Yes":"No");
 return 0;
}