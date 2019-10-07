/*
 Name: luogu P2723
 Author: StudyingFather
 Date: 2019/10/05 23:16
 Website: https://studyingfather.com
*/
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;
struct node
{
 int num,lasta;
 bool operator<(const node&a)const
 {
  return num>a.num;
 }
};
long long a[105];
priority_queue<node> q;
int main()
{
 int k,n;
 cin>>k>>n;
 for(int i=1;i<=k;i++)
 {
  cin>>a[i];
  q.push({a[i],i});
 }
 long long u,num;
 int lasta;
 for(int i=1;;i++)
 {
  u=q.top().num,lasta=q.top().lasta;
  q.pop();
  for(int j=lasta;j<=k;j++)
  {
   num=u*a[j];
   if(num<=2147483647)q.push({num,j});
   else break;
  }
  if(i==n)
  {
   cout<<u<<endl;
   return 0;
  }
 }
}