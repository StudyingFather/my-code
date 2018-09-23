#include <iostream>
#include <algorithm>
#define INF 0x7fffffffffffffff
using namespace std;
long long a[55],b[55];
int main()
{
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 for(int i=1;i<=m;i++)
  cin>>b[i];
 long long res=INF;
 for(int i=1;i<=n;i++)
 {
  long long now=-INF;
  for(int j=1;j<=n;j++)
   if(j!=i)
    for(int k=1;k<=m;k++)
     now=max(now,a[j]*b[k]);
  res=min(res,now);
 }
 cout<<res;
 return 0;
}
