#include <cmath>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
struct node
{
 int y,r;
 bool operator<(const node&a)const
 {
  return y<a.y||(y==a.y&&r<a.r);
 }
}a[50005];
unordered_set<int> s;
int n,f[50005][25];
void init()
{
 for(int i=1;i<=n;i++)
  f[i][0]=a[i].r;
 for(int k=1;k<=16;k++)
  for(int i=1;i+(1<<k)-1<=n;i++)
   f[i][k]=max(f[i][k-1],f[i+(1<<(k-1))][k-1]);
}
int find(int l,int r)
{
 if(l>r)return 0;
 int k=log2(r-l+1);
 return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i].y>>a[i].r;
  s.insert(a[i].y);
 }
 init();
 int q;
 cin>>q;
 while(q--)
 {
  int x,y;
  cin>>y>>x;
  if(!s.count(y)&&!s.count(x))
   cout<<"maybe"<<endl;
  else if(!s.count(y)&&s.count(x))
  {
   int l=lower_bound(a+1,a+n+1,(node){y,0})-a,r=lower_bound(a+1,a+n+1,(node){x,0})-a;
   if(find(l,r-1)>=a[r].r)cout<<"false"<<endl;
   else cout<<"maybe"<<endl;
  }
  else if(s.count(y)&&!s.count(x))
  {
   int l=lower_bound(a+1,a+n+1,(node){y,0})-a,r=lower_bound(a+1,a+n+1,(node){x,0})-a;
   if(find(l+1,r-1)>=a[l].r)cout<<"false"<<endl;
   else cout<<"maybe"<<endl;
  }
  else
  {
   int l=lower_bound(a+1,a+n+1,(node){y,0})-a,r=lower_bound(a+1,a+n+1,(node){x,0})-a;
   if(a[r].r>a[l].r)cout<<"false"<<endl;
   else if(r-l+1==x-y+1)//all information got
   {
    if(find(l+1,r-1)>=a[r].r)cout<<"false"<<endl;
    else cout<<"true"<<endl;
   }
   else
   {
    if(find(l+1,r-1)>=a[r].r)cout<<"false"<<endl;
    else cout<<"maybe"<<endl;
   }
  }
 }
 return 0;
}