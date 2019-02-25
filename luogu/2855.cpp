#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int stone[400100];
int main()
{
 int i,j,mid;
 int l,left,r,n,m;
 scanf("%d%d%d",&l,&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d",&stone[i]);
 sort(stone+1,stone+n+1);
 stone[0]=0;
 stone[n+1]=l;
 left=0;
 r=l+1;
 while(left+1<r)
 {
  mid=(left+r)/2;
  int ans=0;
  i=0;
  while(i<=n)
  {
   j=i+1;
   while(stone[j]-stone[i]<mid&&j<=n+1) 
    j++;
   ans+=j-i-1;
   i=j;
  }
  if(ans<=m)left=mid;
  else r=mid; 
 }
 printf("%d",left);
 return 0;
}