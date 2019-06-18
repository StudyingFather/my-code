#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[15005],b[15005],c[15005],d[15005],w[15005],h[40005],n,m,x,y;
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++) 
 {
  scanf("%d",&h[i]);
  w[h[i]]++;
 }
 for(int i=1;i<=n/9;i++) 
 {
  x=1+9*i,y=0;
  for(int j=2+9*i;j<=n;j++)
  {
   y+=w[j-x]*w[j-x+i+i];
   d[j]+=y*w[j-i];
   c[j-i]+=y*w[j];
  }  
  x=8*i+1,y=0;
  for(int j=n-9*i-1;j>=1;j--)  
  {
   y+=w[j+x]*w[j+x+i];
   a[j]+=y*w[j+i+i];
   b[j+i+i]+=y*w[j];
  }
 }
 for(int i=1;i<=m;i++) 
  printf("%d %d %d %d\n",a[h[i]],b[h[i]],c[h[i]],d[h[i]]);
 return 0;
}