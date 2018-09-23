#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int r[100005],l[100005];
void link(int L,int R)
{
 r[L]=R;
 l[R]=L;
}
int main()
{
 int n,m,kase=0;
 while(cin>>n>>m)
 {
  for(int i=1;i<=n;i++)
  {
   l[i]=i-1;
   r[i]=(i+1)%(n+1);
  }
  r[0]=1;
  l[0]=n;
  int op,X,Y,inv=0;
  while(m--)
  {
   cin>>op;
   if(op==4)inv=!inv;
   else
   {
    cin>>X>>Y;
    if(op==3&&r[Y]==X)swap(X,Y);
    if(op!=3&&inv)op=3-op;
    if(op==1&&X==l[Y])continue;
    if(op==2&&X==r[Y])continue;
    int LX=l[X],RX=r[X],LY=l[Y],RY=r[Y];
    if(op==1)
    {
     link(LX,RX);
     link(LY,X);
     link(X,Y);
    }
    else if(op==2)
    {
     link(LX,RX);
     link(Y,X);
     link(X,RY);
    }
    else if(op==3)
    {
     if(r[X]==Y)
     {
      link(LX,Y);
      link(Y,X);
      link(X,RY);
     }
     else
     {
      link(LX,Y);
      link(Y,RX);
      link(LY,X);
      link(X,RY);
     }
    }
   }
  }
  int b=0;
  long long ans=0;
  for(int i=1;i<=n;i++)
  {
   b=r[b];
   if(i%2==1)ans+=b;
  }
  if(inv&&n%2==0)ans=(long long)n*(n+1)/2-ans;
  cout<<"Case "<<++kase<<": "<<ans<<endl;
 }
 return 0;
}
