// Problem : P5283 [十二省联考2019]异或粽子
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P5283
// Memory Limit : 1024 MB
// Time Limit : 3500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
 unsigned x;
 int rk,id;
 bool operator<(const node&a)const
 {
  return x<a.x;
 }
};
priority_queue<node> q;
unsigned s[500005];
struct trie
{
 int son[20000005][2],siz[20000005],cnt=1;
 void add(unsigned x)
 {
  int u=1;
  for(int i=31;i>=0;i--)
  {
   int p=(x>>i)&1;
   siz[u]++;
   if(!son[u][p])
    son[u][p]=++cnt;
   u=son[u][p];
  }
  siz[u]++;
 }
 unsigned query(unsigned x,int rk)
 {
  unsigned ans=0;
  int u=1;
  for(int i=31;i>=0;i--)
  {
   int p=(x>>i)&1;
   if(rk<=siz[son[u][p^1]])
    u=son[u][p^1],ans|=(1u<<i);
   else
    rk-=siz[son[u][p^1]],u=son[u][p];
  }
  return ans;
 }
}tr;
int main()
{
 ios::sync_with_stdio(false);
 int n,k;
 long long ans=0;
 cin>>n>>k;
 k<<=1;
 for(int i=1;i<=n;i++)
 {
  cin>>s[i];
  s[i]^=s[i-1];
 }
 for(int i=0;i<=n;i++)
  tr.add(s[i]);
 for(int i=0;i<=n;i++)
  q.push({tr.query(s[i],1),1,i});
 while(k--)
 {
  ans+=q.top().x;
  int rk=q.top().rk,id=q.top().id;
  q.pop();
  q.push({tr.query(s[id],rk+1),rk+1,id});
 }
 cout<<ans/2<<endl;
 return 0;
}