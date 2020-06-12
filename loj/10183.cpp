#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int f[2005][2005];
int q[2005];
int main()
{
 int t,maxp,w;
 cin>>t>>maxp>>w;
 memset(f,191,sizeof(f));
 for(int i=1;i<=t;i++)
 {
  int ap,bp,as,bs;
  cin>>ap>>bp>>as>>bs;
  for(int j=0;j<=as;j++)
   f[i][j]=-j*ap;
  for(int j=0;j<=maxp;j++)
   f[i][j]=max(f[i][j],f[i-1][j]);
  int l=0,r=0;
  if(i-w-1<0)continue;
  for(int j=0;j<=maxp;j++)
  {
   while(l<r&&q[l]+as<j)
    l++;
   while(l<r&&f[i-w-1][q[r-1]]+q[r-1]*ap<=f[i-w-1][j]+j*ap)
    r--;
   q[r++]=j;
   f[i][j]=max(f[i][j],f[i-w-1][q[l]]+q[l]*ap-j*ap);
  }
  memset(q,0,sizeof(q));
  l=0,r=0;
  for(int j=maxp;j>=0;j--)
  {
   while(l<r&&q[l]-bs>j)
    l++;
   while(l<r&&f[i-w-1][q[r-1]]+q[r-1]*bp<=f[i-w-1][j]+j*bp)
    r--;
   q[r++]=j;
   f[i][j]=max(f[i][j],f[i-w-1][q[l]]+q[l]*bp-j*bp);
  }
 }
 int ans=0;
 for(int i=0;i<=maxp;i++)
  ans=max(ans,f[t][i]);
 cout<<ans<<endl;
 return 0;
}