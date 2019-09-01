/*
 Name: Atcoder Beginner Contest 138C
 Author: StudyingFather
 Date: 2019/08/18 20:08
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <queue>
using namespace std;
priority_queue<double,vector<double>,greater<double> > q;
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  q.push(x);
 }
 for(int i=1;i<n;i++)
 {
  double tmp1=q.top();
  q.pop();
  double tmp2=q.top();
  q.pop();
  q.push((tmp1+tmp2)/2);
 }
 printf("%.10lf\n",q.top());
 return 0;
}
