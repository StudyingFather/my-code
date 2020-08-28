// Problem: P5948 [POI2003]Chocolate
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5948
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> q1,q2;
int main()
{
 int n,m;
 cin>>n>>m;
 for(int i=1;i<n;i++)
 {
  int x;
  cin>>x;
  q1.push(x);
 }
 for(int i=1;i<m;i++)
 {
  int x;
  cin>>x;
  q2.push(x);
 }
 int cnt1=1,cnt2=1;
 long long ans=0;
 while(!q1.empty()||!q2.empty())
  if(q1.empty())
   ans+=q2.top()*cnt1,q2.pop(),cnt2++;
  else if(q2.empty())
   ans+=q1.top()*cnt2,q1.pop(),cnt1++;
  else if(q1.top()>q2.top())
   ans+=q1.top()*cnt2,q1.pop(),cnt1++;
  else
   ans+=q2.top()*cnt1,q2.pop(),cnt2++;
 cout<<ans<<endl;
 return 0;
}