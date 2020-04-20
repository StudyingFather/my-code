#include <iostream>
#include <algorithm>
using namespace std;
int p[100005],q[100005],r[100005];
int cp=1,cq=1,cr=1,tp,tq;
int x,y,a,b,c;
int get()
{
 int ans=max(p[cp]*(x>0),max(q[cq]*(y>0),r[cr]));
 if(ans==p[cp]&&x)
 {
  cp++,x--;
  return ans;
 }
 else if(ans==q[cq]&&y)
 {
  cq++,y--;
  return ans;
 }
 else
 {
  cr++;
  if(p[tp]<q[tq]&&x)x--,tp--;
  else y--,tq--;
 }
 return ans;
}
bool cmp(int x,int y)
{
 return x>y;
}
int main()
{
 long long ans=0;
 cin>>x>>y>>a>>b>>c;
 for(int i=1;i<=a;i++)
  cin>>p[i];
 for(int i=1;i<=b;i++)
  cin>>q[i];
 for(int i=1;i<=c;i++)
  cin>>r[i];
 tp=x,tq=y;
 sort(p+1,p+a+1,cmp);
 sort(q+1,q+b+1,cmp);
 sort(r+1,r+c+1,cmp);
 while(x+y)
  ans+=get();
 cout<<ans<<endl;
 return 0;
}