// Problem : F. Pudding Monsters
// Contest : Codeforces - ZeptoLab Code Rush 2015
// URL : https://codeforces.com/contest/526/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int a[300005],b[300005];
struct seg
{
 int minn,sum,tag;
}s[1200005];
int smax[300005],smin[300005],tmax,tmin;
void pushup(int root)
{
 s[root].minn=min(s[root<<1].minn,s[root<<1|1].minn);
 s[root].sum=0;
 if(s[root<<1].minn==s[root].minn)
  s[root].sum+=s[root<<1].sum;
 if(s[root<<1|1].minn==s[root].minn)
  s[root].sum+=s[root<<1|1].sum;
}
void build(int root,int l,int r)
{
 s[root].minn=l;
 s[root].sum=1;
 if(l==r)return;
 int mid=(l+r)>>1;
 build(root<<1,l,mid);
 build(root<<1|1,mid+1,r);
 pushup(root);
}
void pushdown(int root)
{
 int tag=s[root].tag;
 s[root<<1].minn+=tag,s[root<<1|1].minn+=tag;
 s[root<<1].tag+=tag,s[root<<1|1].tag+=tag;
 s[root].tag=0;
}
void update(int root,int cl,int cr,int l,int r,int x)
{
 if(cr<l||r<cl)return;
 if(l<=cl&&cr<=r)
 {
  s[root].minn+=x,s[root].tag+=x;
  return;
 }
 pushdown(root);
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r,x);
 update(root<<1|1,mid+1,cr,l,r,x);
 pushup(root);
}
int main()
{
 ios::sync_with_stdio(false);
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int x,y;
  cin>>x>>y;
  a[x]=y;
 }
 build(1,1,n);
 long long ans=0;
 for(int i=1;i<=n;i++)
 {
  update(1,1,n,1,n,-1);
  while(tmax&&a[smax[tmax]]<a[i])
  {
   update(1,1,n,smax[tmax-1]+1,smax[tmax],a[i]-a[smax[tmax]]);
   tmax--;
  }
  smax[++tmax]=i;
  while(tmin&&a[smin[tmin]]>a[i])
  {
   update(1,1,n,smin[tmin-1]+1,smin[tmin],a[smin[tmin]]-a[i]);
   tmin--;
  }
  smin[++tmin]=i;
  ans+=s[1].sum;
 }
 cout<<ans<<endl;
 return 0;
}