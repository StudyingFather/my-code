#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 int x,y,z;
 bool operator<(const node&a)const
 {
  return z<a.z;
 }
}a[250005];
struct query
{
 int x1,y1,x2,y2,k;
}q[60005];
struct BIT
{
 int a[505][505],n;
 void init(int N)
 {
  n=N;
 }
 int lowbit(int x)
 {
  return x&(-x);
 }
 void add(int x,int y,int z)
 {
  for(int i=x;i<=n;i+=lowbit(i))
   for(int j=y;j<=n;j+=lowbit(j))
    a[i][j]+=z;
 }
 int query(int x,int y)
 {
  int ans=0;
  for(int i=x;i;i-=lowbit(i))
   for(int j=y;j;j-=lowbit(j))
    ans+=a[i][j];
  return ans;
 }
 int query_square(int x1,int y1,int x2,int y2)
 {
  return query(x2,y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1);
 }
}bit;
int id[60005],ans[60005],cur[60005];
int q1[60005],q2[60005];
int n,Q;
void solve(int l,int r,int ql,int qr)
{
 if(ql>qr)return;
 if(l==r)
 {
  for(int i=ql;i<=qr;i++)
   ans[id[i]]=a[l].z;
  return;
 }
 int mid=(l+r)>>1;
 for(int i=l;i<=mid;i++)
  bit.add(a[i].x,a[i].y,1);
 int cnt1=0,cnt2=0;
 for(int i=ql;i<=qr;i++)
 {
  int u=id[i];
  int res=cur[u]+bit.query_square(q[u].x1,q[u].y1,q[u].x2,q[u].y2);
  if(res>=q[u].k)
   q1[++cnt1]=u;
  else
   q2[++cnt2]=u,cur[u]=res;
 }
 int cnt3=ql-1;
 for(int i=1;i<=cnt1;i++)
  id[++cnt3]=q1[i];
 for(int i=1;i<=cnt2;i++)
  id[++cnt3]=q2[i];
 for(int i=l;i<=mid;i++)
  bit.add(a[i].x,a[i].y,-1);
 solve(l,mid,ql,ql+cnt1-1);
 solve(mid+1,r,ql+cnt1,qr);
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>Q;
 bit.init(n);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {
   int id=(i-1)*n+j;
   cin>>a[id].z;
   a[id].x=i,a[id].y=j;
  }
 sort(a+1,a+n*n+1);
 for(int i=1;i<=Q;i++)
 {
  cin>>q[i].x1>>q[i].y1>>q[i].x2>>q[i].y2>>q[i].k;
  id[i]=i;
 }
 solve(1,n*n,1,Q);
 for(int i=1;i<=Q;i++)
  cout<<ans[i]<<endl;
 return 0;
}