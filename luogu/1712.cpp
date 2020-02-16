#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
struct SegT
{
 int maxa,tag;
}se[4000005];
struct seg
{
 int l,r,len;
 bool operator<(const seg&a)const
 {
  return len<a.len;
 }
}s[500005];
int p[1000005],cnt;
void pushup(int root)
{
 se[root].maxa=max(se[root<<1].maxa,se[root<<1|1].maxa);
}
void pushdown(int root)
{
 se[root<<1].maxa+=se[root].tag;
 se[root<<1|1].maxa+=se[root].tag;
 se[root<<1].tag+=se[root].tag;
 se[root<<1|1].tag+=se[root].tag;
 se[root].tag=0;
}
void update(int root,int cl,int cr,int l,int r,int x)
{
 if(cr<l||r<cl)return;
 if(l<=cl&&cr<=r)
 {
  se[root].maxa+=x;
  se[root].tag+=x;
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
 int n,m,ans=INF;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
 {
  cin>>s[i].l>>s[i].r;
  p[++cnt]=s[i].l;
  p[++cnt]=s[i].r;
  s[i].len=s[i].r-s[i].l;
 }
 sort(p+1,p+cnt+1);
 cnt=unique(p+1,p+cnt+1)-p-1;
 for(int i=1;i<=n;i++)
 {
  s[i].l=lower_bound(p+1,p+cnt+1,s[i].l)-p;
  s[i].r=lower_bound(p+1,p+cnt+1,s[i].r)-p;
 }
 sort(s+1,s+n+1);
 int l=1;
 for(int r=1;r<=n;r++)
 {
  update(1,1,cnt,s[r].l,s[r].r,1);
  while(se[1].maxa>=m)
  {
   ans=min(ans,s[r].len-s[l].len);
   update(1,1,cnt,s[l].l,s[l].r,-1);
   l++;
  }
 }
 if(ans==INF)cout<<-1<<endl;
 else cout<<ans<<endl;
 return 0;
}