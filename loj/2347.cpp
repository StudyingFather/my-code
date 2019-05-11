#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int> h;
int t[100005];
int main()
{
 int n,k,ans;
 scanf("%d%d",&n,&k);
 k--;
 for(int i=1;i<=n;i++)
  scanf("%d",&t[i]);
 ans=t[n]+1-t[1];
 for(int i=1;i<n;i++)
  h.push(t[i+1]-t[i]-1);
 while(k--)
 {
  ans-=h.top();
  h.pop();
 }
 printf("%d\n",ans);
 return 0;
}