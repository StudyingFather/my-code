#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[200005],cnt,f[200005][25];
void update(int x)
{
 f[x][0]=a[x];
 for(int i=1;(1<<i)<=x;i++)
  f[x][i]=max(f[x][i-1],f[x-(1<<(i-1))][i-1]);
}
long long query(int l,int r)
{
 int k=log2(r-l+1);
 return max(f[r][k],f[l+(1<<k)-1][k]);
}
int main()
{
 long long m,d,lastans=0;
 cin>>m>>d;
 for(int i=1;i<=m;i++)
 {
  char c;
  cin>>c;
  if(c=='A')
  {
   long long x;
   cin>>x;
   a[++cnt]=(x+lastans)%d;
   update(cnt);
  }
  else
  {
   long long x;
   cin>>x;
   cout<<(lastans=query(cnt-x+1,cnt))<<endl;
  }
 }
 return 0;
}