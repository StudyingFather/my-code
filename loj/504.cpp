// Problem: #504. 「LibreOJ β Round」ZQC 的手办
// Contest: LibreOJ
// URL: https://loj.ac/problem/504
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct seg
{
 int mina,pos,tag;
 bool operator<(const seg&a)const
 {
  return mina<a.mina||(mina==a.mina&&pos<a.pos);
 }
}s[2000005];
struct node
{
 int l,r,mina,pos;
 bool operator>(const node&a)const
 {
  return mina>a.mina||(mina==a.mina&&pos>a.pos);
 }
};
int a[500005];
void pushup(int root)
{
 if(s[root<<1].mina<s[root<<1|1].mina)
  s[root].mina=s[root<<1].mina,s[root].pos=s[root<<1].pos;
 else
  s[root].mina=s[root<<1|1].mina,s[root].pos=s[root<<1|1].pos;
}
void pushdown(int root,int l,int r)
{
 if(s[root].tag)
 {
  int tag=s[root].tag;
  s[root<<1].mina=max(s[root<<1].mina,tag);
  s[root<<1|1].mina=max(s[root<<1|1].mina,tag);
  s[root<<1].tag=s[root<<1|1].tag=tag;
  s[root].tag=0;
 }
}
void build(int root,int l,int r)
{
 if(l==r)
 {
  s[root].mina=a[l],s[root].pos=l;
  return;
 }
 int mid=(l+r)>>1;
 build(root<<1,l,mid);
 build(root<<1|1,mid+1,r);
 pushup(root);
}
void update(int root,int cl,int cr,int l,int r,int x)
{
 if(r<cl||cr<l)return;
 if(l<=cl&&cr<=r)
 {
  if(x>s[root].mina)
   s[root].mina=x,s[root].tag=x;
  return;
 }
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r,x);
 update(root<<1|1,mid+1,cr,l,r,x);
 pushup(root);
}
seg query(int root,int cl,int cr,int l,int r)
{
 if(r<cl||cr<l)return {1<<30,0,0};
 if(l<=cl&&cr<=r)return s[root];
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 return min(query(root<<1,cl,mid,l,r),query(root<<1|1,mid+1,cr,l,r));
}
int main()
{
 ios::sync_with_stdio(false);
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 build(1,1,n);
 int Q;
 cin>>Q;
 while(Q--)
 {
  int op;
  cin>>op;
  if(op==1)
  {
   int a,b,k;
   cin>>a>>b>>k;
   update(1,1,n,a,b,k);
  }
  else
  {
   vector<int> res;
   priority_queue<node,vector<node>,greater<node> > q;
   int a,b,k,x;
   cin>>a>>b>>k>>x;
   seg tmp=query(1,1,n,a,b);
   q.push({a,b,tmp.mina,tmp.pos});
   while(!q.empty())
   {
    node u=q.top();
    q.pop();
    if((int)res.size()>=x||u.mina>=k)break;
    res.push_back(u.mina);
    int l=u.l,r=u.r,pos=u.pos;
    if(l<pos)
    {
     tmp=query(1,1,n,l,pos-1);
     q.push({l,pos-1,tmp.mina,tmp.pos});
    }
    if(pos<r)
    {
     tmp=query(1,1,n,pos+1,r);
     q.push({pos+1,r,tmp.mina,tmp.pos});
    }
   }
   if((int)res.size()<x)cout<<-1;
   else
    for(auto x:res)
     cout<<x<<' ';
   cout<<endl;
  }
 }
 return 0;
}