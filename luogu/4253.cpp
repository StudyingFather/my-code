#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
long long f[200005][25][2],w[200005][25];
int a[200005],n;
int find(int x,int y)
{
 return (x>>(y-1))^1;
}
int main()
{
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 for(int i=2;i<=n;i++)
  cin>>w[i][1];
 for(int i=2;i<=20;i++)
  for(int j=n;j>>i;j--)
   w[j][i]=w[j][i-1]+w[j>>(i-1)][1];
 for(int i=n;i;i--)
 {
  if((i<<1)>n)
   for(int j=1;i>>(j-1);j++)
   {
    f[i][j][0]=(w[i][j]+w[find(i,j)][1])*a[find(i,j)];
    f[i][j][1]=w[i][j]*a[i>>j];
   }
  else if((i<<1|1)>n)
   for(int j=1;i>>(j-1);j++)
   {
    f[i][j][0]=w[i<<1][1]*a[i<<1]+f[i<<1][j+1][0];
    f[i][j][1]=w[i<<1][1]*a[i<<1]+f[i<<1][j+1][1];
   }
  else
   for(int j=1;i>>(j-1);j++)
   {
    f[i][j][0]=min(w[i<<1][1]*a[i<<1]+f[i<<1][1][0]+f[i<<1|1][j+1][0],
                   w[i<<1|1][1]*a[i<<1|1]+f[i<<1|1][1][0]+f[i<<1][j+1][0]);
    f[i][j][1]=min(w[i<<1][1]*a[i<<1]+f[i<<1][1][0]+f[i<<1|1][j+1][1],
                   w[i<<1|1][1]*a[i<<1|1]+f[i<<1|1][1][0]+f[i<<1][j+1][1]);
   }
 }
 long long ans=1e18;
 for(int i=1;i<=n;i++)
 {
  long long res=f[i][1][1];
  for(int j=1,fa=(i>>1);fa;j++,fa>>=1)
  {
   int p=find(i,j);
   if(p>n)res+=w[fa][1]*a[fa>>1];
   else res+=w[p][1]*a[p]+f[p][2][1];
  }
  ans=min(ans,res);
 }
 cout<<ans<<endl;
 return 0;
}