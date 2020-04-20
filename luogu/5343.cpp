#include <cstring>
#include <iostream>
#define MOD 1000000007
using namespace std;
struct mat
{
 long long a[105][105];
 mat()
 {
  memset(a,0,sizeof(a));
 }
 mat operator*(const mat&b)const
 {
  mat ans;
  for(int k=0;k<=100;k++)
   for(int i=0;i<=100;i++)
    for(int j=0;j<=100;j++)
     ans.a[i][j]=(ans.a[i][j]+a[i][k]*b.a[k][j])%MOD;
  return ans;
 }
}f,g;
long long n;
int vis[105];
mat fpow(mat x,long long y)
{
 mat ans;
 for(int i=0;i<=100;i++)
  ans.a[i][i]=1;
 while(y)
 {
  if(y&1)ans=ans*x;
  x=x*x;
  y>>=1;
 }
 return ans;
}
int main()
{
 memset(vis,-1,sizeof(vis));
 cin>>n;
 int p;
 cin>>p;
 while(p--)
 {
  int x;
  cin>>x;
  if(vis[x]==-1)vis[x]++;
 }
 cin>>p;
 while(p--)
 {
  int x;
  cin>>x;
  if(vis[x]==0)vis[x]++;
 }
 f.a[0][0]=1;
 for(int i=1;i<=100;i++)
  for(int j=1;j<=i;j++)
   if(vis[j]==1)
    f.a[0][i]=(f.a[0][i]+f.a[0][i-j])%MOD;
 for(int i=1;i<=100;i++)
  g.a[i][i-1]=1;
 for(int i=1;i<=100;i++)
  if(vis[i]==1)
   g.a[101-i][100]=1;
 if(n<=100)cout<<f.a[0][n]<<endl;
 else cout<<(f*fpow(g,n-100)).a[0][100]<<endl;
 return 0;
}