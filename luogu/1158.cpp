#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct Mis
{
 int w1,w2;
};
int cmp(const Mis&a,const Mis&b)
{
 return a.w1<b.w1;
}
Mis w[100005];
int xa,ya,xb,yb;
int n;
int main()
{
 scanf("%d%d%d%d%d",&xa,&ya,&xb,&yb,&n);
 for(int i=1;i<=n;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  w[i].w1=(xa-x)*(xa-x)+(ya-y)*(ya-y);
  w[i].w2=(xb-x)*(xb-x)+(yb-y)*(yb-y);
 }
 sort(w+1,w+1+n,cmp);
 int ans=w[n].w1,r=0; 
 for(int i=n;i>=1;i--)
 {
  ans=min(ans,w[i].w1+r);
  r=max(r,w[i].w2); 
 }
 printf("%d",ans);
 return 0;
}
