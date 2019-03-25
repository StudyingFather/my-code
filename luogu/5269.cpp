#include <iostream>
#include <algorithm>
using namespace std;
long long T,N,L,R,X,K;
int main()
{
 ios::sync_with_stdio(false);
 cin>>T>>N>>L>>R>>X>>K;
 long long curd=1,curr=L,ans=0,t=0;
 for(int i=1;i<=T;i++)
 {
  int x,y;
  cin>>x>>y;
  if(x==0)curd++,curr=L;
  if(x==1)curd--,curr=R;
  if(curd<1||curd>N)
  {
   cout<<-1<<endl;
   return 0;
  }
  if(y)curr=min(curr+X,R);
  ans+=curr*curd;
  if(curr==R)t++;
  else t=0;
  if(t==K)
  {
   cout<<ans<<endl;
   return 0;
  }
 }
 cout<<ans<<endl;
 return 0;
}