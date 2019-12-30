#include <iostream>
#include <algorithm>
#define MOD 998244353
using namespace std;
struct point
{
 long long x,y,z;
}p[10005];
long long c[65][65],f[65][65][65],g[10005];
bool cmp(const point&a,const point&b)
{
 return a.x<b.x||(a.x==b.x&&(a.y<b.y||(a.y==b.y&&a.z<b.z)));
}
int bitcount(long long x)
{
 int ans=0;
 while(x)
 {
  ans+=x&1;
  x>>=1;
 }
 return ans;
}
int main()
{
 long long n,m,r,o;
 cin>>n>>m>>r>>o;
 for(int i=1;i<=o;i++)
  cin>>p[i].x>>p[i].y>>p[i].z;
 o++;
 p[o].x=n,p[o].y=m,p[o].z=r;
 sort(p+1,p+o+1,cmp);
 c[0][0]=1;
 for(int i=1;i<=64;i++)
 {
  c[i][0]=1;
  for(int j=1;j<=i;j++)
   c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
 }
 f[0][0][0]=1;
 for(int i=0;i<=64;i++)
  for(int j=0;j<=64;j++)
   for(int k=0;k<=64;k++)
   {
    if(i)
     for(int l=1;l<=i;l++)
      f[i][j][k]=(f[i][j][k]+f[i-l][j][k]*c[i][l])%MOD;
    if(j)
     for(int l=1;l<=j;l++)
      f[i][j][k]=(f[i][j][k]+f[i][j-l][k]*c[j][l])%MOD;
    if(k)
     for(int l=1;l<=k;l++)
      f[i][j][k]=(f[i][j][k]+f[i][j][k-l]*c[k][l])%MOD;
   }
 for(int i=1;i<=o;i++)
 {
  long long x=p[i].x,y=p[i].y,z=p[i].z;
  g[i]=f[bitcount(x)][bitcount(y)][bitcount(z)];
  for(int j=1;j<i;j++)
  {
   long long x1=p[j].x,y1=p[j].y,z1=p[j].z;
   if((x1&x)!=x1||(y1&y)!=y1||(z1&z)!=z1)continue;
   int bx=bitcount(x^x1),by=bitcount(y^y1),bz=bitcount(z^z1);
   g[i]=((g[i]-g[j]*f[bx][by][bz])%MOD+MOD)%MOD;
  }
 }
 cout<<g[o]<<endl;
 return 0;
}