#include <iostream>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
 int n;
 long long ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  while(!q.empty()&&x>=2)
  {
   int u=q.top();
   q.pop();
   int res=min(u,x/2);
   ans+=res;
   x-=res*2,u-=res;
   if(u>0)
    q.push(u);
  }
  ans+=x/3;
  x%=3;
  q.push(x);
 }
 while(!q.empty())
 {
  int u=q.top();
  q.pop();
  ans+=u/3;
 }
 cout<<ans<<endl;
 return 0;
}