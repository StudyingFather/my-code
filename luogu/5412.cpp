/*
 Name: luogu P5412
 Author: StudyingFather
 Date: 2019/08/05 10:18
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int a[10005],n;
priority_queue<double,vector<double>,greater<double> > q1,q2;
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
   scanf("%d",&a[i]);
  for(int i=1;i<=n;i++)
  {
   double h;
   scanf("%lf",&h);
   if(!a[i])q1.push(h);
   else q2.push(h);
  }
  while(!q1.empty())
  {
   printf("%g ",q1.top());
   q1.pop();
  }
  puts("");
  while(!q2.empty())
  {
   printf("%g ",q2.top());
   q2.pop();
  }
 }
 return 0;
}