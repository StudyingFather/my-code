#include <iostream>
#include <algorithm> 
#include <cstdio>
using namespace std;
int q1[10005],q2[10005];
int n,cnt1,cnt2;
int main()
{
 scanf("%d",&n);
 getchar();
 for(int i=1;i<=n;i++)
 {
  char c;
  scanf("%c ",&c);
  if(c=='T')cnt1++,scanf("%d",&q1[cnt1]);
  else cnt2++,scanf("%d",&q2[cnt2]);
  getchar();
 }
 sort(q1+1,q1+cnt1+1);
 sort(q2+1,q2+cnt2+1);
 int cur1=1,cur2=1,curv=1;
 double t=0,curx=0;
 while(cur1<=cnt1||cur2<=cnt2)
 {
  double x=curx,downx=10000;
  if(cur1<=cnt1)x+=(q1[cur1]-t)*1.0/curv;
  if(cur2<=cnt2)downx=q2[cur2];
  if(x<downx&&cur1<=cnt1)
  {
   t=q1[cur1];
   curx=x;
   curv++;
   cur1++;
  }
  else if(cur2<=cnt2)
  {
   t+=(q2[cur2]-curx)*curv;
   curx=downx;
   curv++;
   cur2++;
  }
 }
 t+=(1000-curx)*curv;
 printf("%.0lf\n",t);
 return 0;
}
