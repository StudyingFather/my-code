#include <cstdio>
#include <stack>
using namespace std;
int fa[200005];
stack<int> s;
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=2;i<=n;i++)
  scanf("%d",&fa[i]);
 for(int i=n;i;i=fa[i])
  s.push(i);
 while(!s.empty())
 {
  printf("%d ",s.top());
  s.pop();
 }
 return 0;
}