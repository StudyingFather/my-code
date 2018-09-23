#include <cstdio>
using namespace std;
int main()
{
 int n,x;
 scanf("%d",&n);
 int cnt=0,ans;
 for(int i=0;i<n;i++)
 {
  scanf("%d",&x);
  if(cnt==0)ans=x;
  (ans==x)?cnt++:cnt--;
 }
 printf("%d\n",ans);
 return 0;
}
