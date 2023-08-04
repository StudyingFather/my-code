#include <cstdio>
#include <cstring>
char s[500005],ch[5];
int res[2000005][35],ans[35];
void merge(int root)
{
 for(int i=0;i<=25;i++)
  ans[i]+=res[root][i];
}
void update(int root,int l,int r,int p,int x,int op)
{
 if(r<p||p<l)return;
 if(op)res[root][s[p]]--;
 res[root][x]++;
 if(l==r)return;
 int mid=(l+r)>>1;
 update(root<<1,l,mid,p,x,op);
 update(root<<1|1,mid+1,r,p,x,op);
}
void query(int root,int cl,int cr,int l,int r)
{
 if(cr<l||r<cl)return;
 if(l<=cl&&cr<=r)
 {
  merge(root);
  return;
 }
 int mid=(cl+cr)>>1;
 query(root<<1,cl,mid,l,r);
 query(root<<1|1,mid+1,cr,l,r);
}
int main()
{
 int n,q;
 scanf("%d",&n);
 scanf("%s",s+1);
 for(int i=1;i<=n;i++)
  s[i]-='a',update(1,1,n,i,s[i],0);
 scanf("%d",&q);
 while(q--)
 {
  int op;
  scanf("%d",&op);
  if(op==1)
  {
   int p;
   scanf("%d",&p);
   scanf("%s",ch);
   ch[0]-='a';
   update(1,1,n,p,ch[0],1);
   s[p]=ch[0];
  }
  else
  {
   memset(ans,0,sizeof(ans));
   int l,r,cnt=0;
   scanf("%d%d",&l,&r);
   query(1,1,n,l,r);
   for(int i=0;i<=25;i++)
    cnt+=(ans[i]>0);
   printf("%d\n",cnt);
  }
 }
 return 0;
}