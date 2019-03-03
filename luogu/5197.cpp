#include <cstdio>
#include <algorithm>
using namespace std;
int t[100005],ans;
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<n;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  t[x]++,t[y]++;
  ans=max(ans,max(t[x],t[y]));
 }
 printf("%d\n",ans+1);
 return 0;
}
