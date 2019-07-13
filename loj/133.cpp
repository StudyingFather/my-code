#include <iostream>
#include <algorithm>
using namespace std;
long long a[5005][5005],n,m;
int lowbit(int x)
{
 return x&(-x);
}
void add(int x,int y,int k)
{
 for(int i=x;i<=n;i+=lowbit(i))
  for(int j=y;j<=m;j+=lowbit(j))
   a[i][j]+=k;
}
long long query(int x,int y)
{
 long long ans=0;
 for(int i=x;i;i-=lowbit(i))
  for(int j=y;j;j-=lowbit(j))
   ans+=a[i][j];
 return ans;
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>m;
 int op;
 while(cin>>op)
 {
  if(op==1)
  {
   int x,y,k;
   cin>>x>>y>>k;
   add(x,y,k);
  }
  else
  {
   int a,b,c,d;
   cin>>a>>b>>c>>d;
   cout<<query(c,d)-query(a-1,d)-query(c,b-1)+query(a-1,b-1)<<endl;
  }
 }
 return 0;
}