#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int main()
{
 int n,ans;
 cin>>n;
 ans=n;
 for(int i=1;i<=n;i++)
 {
  int tmp,x;
  cin>>tmp>>x;
  while(!s.empty()&&s.top()>=x)
  {
   if(s.top()==x)ans--;
   s.pop();
  }
  s.push(x);
 }
 cout<<ans<<endl;
 return 0;
}