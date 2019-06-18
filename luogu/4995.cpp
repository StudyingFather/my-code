#include <iostream>
#include <algorithm>
using namespace std;
int h[305],vis[305];
int main()
{
 int n;
 long long ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
  scanf("%d",&h[i]);
 int curh=0;
 for(int i=1;i<=n;i++)
 {
  int maxd=0,to;
  for(int j=1;j<=n;j++)
   if((!vis[j])&&abs(curh-h[j])>=maxd)
   {
    to=j;
    maxd=abs(curh-h[j]);
   }
  ans+=maxd*maxd;
  vis[to]=1;
  curh=h[to];
 }
 cout<<ans<<endl;
 return 0;
}