#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q;
int main()
{
 ios::sync_with_stdio(false);
 int m,ans=0;
 long long x=0;
 cin>>m;
 for(int i=1;i<=m;i++)
 {
  int op,a,b;
  cin>>op;
  if(op==1)
  {
   cin>>a;
   x+=a;
  }
  else if(op==2)
  {
   cin>>a;
   while(!q.empty()&&q.top().first<=i)
   {
    x+=q.top().second;
    q.pop();
   }
   if(x>=a)x-=a;
   else ans++;
  }
  else
  {
   cin>>a>>b;
   q.push({b,a});
   x-=a;
  }
 }
 cout<<ans<<endl;
 return 0;
}