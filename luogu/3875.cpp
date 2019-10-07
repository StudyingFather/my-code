/*
 Name: luogu P3875
 Author: StudyingFather
 Date: 2019/09/30 23:42
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct line
{
 int x,l,r,val;
}l[200005];
struct seg
{
 int cnt,len;
}s[4000005];
bool cmp(const line&a,const line&b)
{
 return a.x<b.x;
}
void pushup(int root,int l,int r)
{
 if(s[root].cnt)s[root].len=r-l+1;
 else s[root].len=s[root<<1].len+s[root<<1|1].len;
}
void update(int root,int cl,int cr,int l,int r,int val)
{
 if(r<cl||cr<l)return;
 if(l<=cl&&cr<=r)
 {
  s[root].cnt+=val;
  pushup(root,cl,cr);
  return;
 }
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r,val);
 update(root<<1|1,mid+1,cr,l,r,val);
 pushup(root,cl,cr);
}
int main()
{
 int n,cnt=0;
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
  int x1,y1,x2,y2;
  scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
  if(x1>x2)swap(x1,x2);
  if(y1>y2)swap(y1,y2);
  if(x1==x2)
  {
   l[++cnt].x=x1-1,l[cnt].l=y1,l[cnt].r=y2,l[cnt].val=1;
   l[++cnt].x=x1+1,l[cnt].l=y1,l[cnt].r=y2,l[cnt].val=-1;
  }
  else
  {
   l[++cnt].x=x1,l[cnt].l=y1-1,l[cnt].r=y1+1,l[cnt].val=1;
   l[++cnt].x=x2,l[cnt].l=y1-1,l[cnt].r=y1+1,l[cnt].val=-1;
  }
 }
 sort(l+1,l+cnt+1,cmp);
 int ans=0;
 for(int i=1;i<=cnt;i++)
 {
  ans+=(l[i].x-l[i-1].x)*s[1].len;
  update(1,0,100005,l[i].l,l[i].r-1,l[i].val);
 }
 printf("%d\n",ans);
 return 0;
}