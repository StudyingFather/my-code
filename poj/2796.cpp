#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct node
{
 int l,r;
 long long num;
}s[100005];
long long a[100005],sum[100005],ans;
int ans_l,ans_r;
void update(int top)
{
 int l=s[top].l,r=s[top].r;
 if((sum[r]-sum[l-1])*s[top].num>ans)
 {
  ans=(sum[r]-sum[l-1])*s[top].num;
  ans_l=l;
  ans_r=r;
 }
 if(top>0)s[top-1].r=s[top].r;
}
int main()
{
 ios::sync_with_stdio(false);
 int n;
 while(cin>>n)
 {
  ans=-1;
  int top=-1;
  sum[0]=0;
  for(int i=1;i<=n;i++)
  {
   cin>>a[i];
   sum[i]=sum[i-1]+a[i];
  }
  for(int i=1;i<=n;i++)
  {
   node v={i,i,a[i]};
   while(top!=-1&&s[top].num>=a[i])
   {
    update(top);
    v.l=s[top].l;
    top--;
   }
   s[++top].l=v.l;
   s[top].r=v.r;
   s[top].num=v.num;
  }
  while(top!=-1)
  {
   update(top);
   top--;
  }
  cout<<ans<<endl;
  cout<<ans_l<<' '<<ans_r<<endl;
 }
 return 0;
}
