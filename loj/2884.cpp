#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 int a,b;
}p[2005];
bool cmp(const node&a,const node&b)
{
 return a.a>b.a;
}
int f[2][2005];
int main()
{
 int n;
 cin>>n;
 memset(f,191,sizeof(f));
 f[0][1]=0;
 for(int i=1;i<=n;i++)
  cin>>p[i].a>>p[i].b;
 sort(p+1,p+n+1,cmp);
 for(int i=1;i<=n;i++)
 {
  int a=p[i].a,b=p[i].b;
  for(int j=0;j<=n;j++)
  {
   f[i&1][j]=f[!(i&1)][j];
   if(j-a>=0)
    f[i&1][j]=max(f[i&1][j],f[!(i&1)][j-a+1]+b);
  }
 }
 int ans=0;
 for(int i=0;i<=n;i++)
  ans=max(ans,f[n&1][i]);
 cout<<ans<<endl;
 return 0;
}