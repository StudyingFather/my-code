/*
 Name: luogu P3871
 Author: StudyingFather
 Date: 2019/09/24 23:54
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <queue>
using namespace std;
priority_queue<int> q1;
priority_queue<int,vector<int>,greater<int> > q2;
int siz1,siz2;
char s[5];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  q1.push(x);
 }
 siz1=n;
 int q;
 scanf("%d",&q);
 while(q--)
 {
  scanf("%s",s);
  if(s[0]=='a')
  {
   int x;
   scanf("%d",&x);
   if(x<=q1.top())q1.push(x),siz1++;
   else q2.push(x),siz2++;
  }
  else
  {
   while(siz1>siz2)
   {
    q2.push(q1.top());
    q1.pop();
    siz1--,siz2++;
   }
   while(siz1<siz2)
   {
    q1.push(q2.top());
    q2.pop();
    siz2--,siz1++;
   }
   printf("%d\n",q1.top());
  }
 }
 return 0;
}