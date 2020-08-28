
// Problem : #3302. 「联合省选 2020 A | B」信号传递
// Contest : LibreOJ
// URL : https://loj.ac/problem/3302
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
 int s;
 int v[23];
};
int n,m,k;
int s[100005],t[23][23],id[9000005],popc[9000005];
int f[9000005];
queue<node> q;
int lowbit(int x)
{
 return x&(-x);
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>m>>k;
 for(int i=1;i<=n;i++)
 {
  cin>>s[i];
  s[i]--;
 }
 for(int i=1;i<n;i++)
  t[s[i]][s[i+1]]++;
 memset(f,63,sizeof(f));
 f[0]=0;
 int S=(1<<m)-1;
 node sta;
 sta.s=0;
 for(int i=0;i<m;i++)
 {
  sta.v[i]=0;
  for(int j=0;j<m;j++)
   if(i!=j)
    sta.v[i]-=t[i][j],sta.v[i]+=k*t[j][i];
 }
 q.push(sta);
 for(int i=1;i<=S;i++)
  popc[i]=popc[i>>1]+(i&1);
 for(int i=0;i<m;i++)
  id[1<<i]=i;
 while(!q.empty())
 {
  node cur=q.front();
  q.pop();
  int p=popc[cur.s]+1;
  for(int T=S^cur.s;T;T-=lowbit(T))
  {
   int x=id[lowbit(T)];
   int ns=cur.s|lowbit(T);
   f[ns]=min(f[ns],f[cur.s]+p*cur.v[x]);
  }
  for(int i=0;i<m;i++)
  {
   if(cur.s&(1<<i))break;
   node next;
   next.s=cur.s|(1<<i);
   for(int T=S^next.s;T;T-=lowbit(T))
   {
    int x=id[lowbit(T)];
    next.v[x]=cur.v[x]+(k*t[x][i]+t[i][x])-(k*t[i][x]-t[x][i]);
   }
   q.push(next);
  }
 }
 cout<<f[S]<<endl;
 return 0;
}