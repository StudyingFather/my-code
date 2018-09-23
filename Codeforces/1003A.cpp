#include <cstdio>
#include <algorithm>
using namespace std;
int t[105],ans;
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int num;
  scanf("%d",&num);
  t[num]++;
  ans=max(ans,t[num]);
 }
 printf("%d",ans);
 return 0;
}
