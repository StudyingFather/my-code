#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int>q;
long long ans;
int main()
{
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  ans+=x;
  q.push(x);
 }
 while(m--)
 {
  int x=q.top();
  q.pop();
  ans=ans-x+x/2;
  q.push(x/2);
 }
 cout<<ans<<endl;
 return 0;
}
