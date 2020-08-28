// Problem : #2132. 「NOI2015」荷马史诗
// Contest : LibreOJ
// URL : https://loj.ac/problem/2132
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<long long,int> pli;
priority_queue<pli,vector<pli>,greater<pli> > q;
int main()
{
 int n,k;
 long long ans=0;
 cin>>n>>k;
 for(int i=1;i<=n;i++)
 {
  long long w;
  cin>>w;
  q.push(make_pair(w,0));
 }
 if((n-1)%(k-1)!=0)
 {
  int x=(k-1)-(n-1)%(k-1);
  while(x--)
   q.push(make_pair(0,0));
 }
 while((int)q.size()>=k)
 {
  int nh=0;
  long long nw=0;
  for(int i=1;i<=k;i++)
  {
   nh=max(nh,q.top().second);
   nw+=q.top().first;
   q.pop();
  }
  ans+=nw;
  q.push(make_pair(nw,nh+1));
 }
 cout<<ans<<endl;
 cout<<q.top().second<<endl;
 return 0;
}