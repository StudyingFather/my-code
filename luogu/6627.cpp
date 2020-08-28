// Problem : P6627 [省选联考 2020 B 卷] 幸运数字
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P6627
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 int op;
 int x,y,w;
}a[100005];
int p[500005],s[2000005],ans=-1,pos,cnt;
void update(int root,int cl,int cr,int l,int r,int x)
{
 if(cr<l||r<cl)return;
 if(l<=cl&&cr<=r)
 {
  s[root]^=x;
  return;
 }
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r,x);
 update(root<<1|1,mid+1,cr,l,r,x);
}
void query(int root,int l,int r,int w)
{
 w^=s[root];
 if(l==r)
 {
  int cp=p[l];
  if(w>ans)ans=w,pos=cp;
  else if(w==ans)
  {
   if(abs(cp)<abs(pos))pos=cp;
   else if(abs(cp)==abs(pos)&&cp>pos)pos=cp;
  }
  return;
 }
 int mid=(l+r)>>1;
 query(root<<1,l,mid,w);
 query(root<<1|1,mid+1,r,w);
}
int main()
{
 ios::sync_with_stdio(false);
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i].op;
  if(a[i].op==1)
  {
   cin>>a[i].x>>a[i].y>>a[i].w;
   p[++cnt]=a[i].x-1;
   p[++cnt]=a[i].x;
   p[++cnt]=a[i].y;
   p[++cnt]=a[i].y+1;
  }
  else
  {
   cin>>a[i].x>>a[i].w;
   p[++cnt]=a[i].x-1;
   p[++cnt]=a[i].x;
   p[++cnt]=a[i].x+1;
  }
 }
 p[++cnt]=0,p[++cnt]=-1e9,p[++cnt]=1e9;
 sort(p+1,p+cnt+1);
 cnt=unique(p+1,p+cnt+1)-p-1;
 for(int i=1;i<=n;i++)
 {
  a[i].x=lower_bound(p+1,p+cnt+1,a[i].x)-p;
  a[i].y=lower_bound(p+1,p+cnt+1,a[i].y)-p;
  if(a[i].op==1)
   update(1,1,cnt,a[i].x,a[i].y,a[i].w);
  else if(a[i].op==2)
   update(1,1,cnt,a[i].x,a[i].x,a[i].w);
  else
  {
   update(1,1,cnt,1,a[i].x-1,a[i].w);
   update(1,1,cnt,a[i].x+1,cnt,a[i].w);
  }
 }
 query(1,1,cnt,0);
 cout<<ans<<' '<<pos<<endl;
 return 0;
}