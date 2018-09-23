#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int a[505],b[505],x[505],y[505],g[505][505],sum[505][505],n,C,tx,ty;
bool check(int k)
{
 int ans=0;
 for(int i=1;i<=tx;i++)
  for(int j=1;j<=ty;j++)
  {
   int ii=upper_bound(x+i,x+tx+1,x[i]+k)-x-1;
   int jj=upper_bound(y+j,y+ty+1,y[j]+k)-y-1;
   ans=max(ans,sum[ii][jj]-sum[ii][j-1]-sum[i-1][jj]+sum[i-1][j-1]);
   if(ans>=C)return true;
  }
 return ans>=C;
}
int main()
{
 int m=-1;
 scanf("%d%d",&C,&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d",&a[i],&b[i]);
  x[i]=a[i];
  y[i]=b[i];
  m=max(m,x[i]);
  m=max(m,y[i]);
 }
 sort(x+1,x+n+1);
 sort(y+1,y+n+1);
 for(int i=1;i<=n;i++)
 {
  if(x[i]!=x[i-1])x[++tx]=x[i];
  if(y[i]!=y[i-1])y[++ty]=y[i];
 }
 for(int i=1;i<=n;i++)
 {
  int px=lower_bound(x+1,x+tx+1,a[i])-x;
  int py=lower_bound(y+1,y+ty+1,b[i])-y;
  g[px][py]++;
 }
 for(int i=1;i<=tx;i++)
  for(int j=1;j<=ty;j++)
   sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+g[i][j];
 int l=0,r=m,mid;
 while(l<r)
 {
  mid=(l+r)>>1;
  if(check(mid))r=mid;
  else l=mid+1;
 }
 printf("%d",r+1);
 return 0;
}
