#include <cstdio>
#include <stack>
using namespace std;
stack<int> s;
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  ans+=s.size();
  int a;
  scanf("%d",&a);
  while(!s.empty()&&a>s.top())
   s.pop();
  s.push(a);
 }
 printf("%d",ans);
 return 0;
}
