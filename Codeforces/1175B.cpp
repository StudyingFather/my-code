#include <iostream>
#include <stack>
using namespace std;
const long long INF=1ll<<32;
stack<long long> sta;
char op[5];
int main()
{
 ios::sync_with_stdio(false);
 long long l,ans=0;
 cin>>l;
 sta.push(1);
 for(int i=1;i<=l;i++)
 {
  int x;
  cin>>op;
  if(op[0]=='a')ans+=sta.top();
  else if(op[0]=='f')
  {
   cin>>x;
   sta.push(min(INF,sta.top()*x));
  }
  else sta.pop();
 }
 if(ans<INF)cout<<ans<<endl;
 else cout<<"OVERFLOW!!!"<<endl;
 return 0;
}