// Problem : P5470 [NOI2019]序列
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P5470
// Memory Limit : 500 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct node
{
 int id,x;
 bool operator<(const node&a)const
 {
  return x<a.x;
 }
};
priority_queue<node> q1,q2;//free flow, all available numbers
priority_queue<node> q3;//add a pair directly
priority_queue<node> q4,q5;//only single number
int a[200005],b[200005];
int vis1[200005],vis2[200005];
int main()
{
 ios::sync_with_stdio(false);
 int T;
 cin>>T;
 while(T--)
 {
  memset(vis1,0,sizeof(vis1));
  memset(vis2,0,sizeof(vis2));
  while(!q1.empty())
   q1.pop();
  while(!q2.empty())
   q2.pop();
  while(!q3.empty())
   q3.pop();
  while(!q4.empty())
   q4.pop();
  while(!q5.empty())
   q5.pop();
  int n,k,l;
  long long ans=0;
  cin>>n>>k>>l;
  for(int i=1;i<=n;i++)
  {
   cin>>a[i];
   q1.push({i,a[i]});
  }
  for(int i=1;i<=n;i++)
  {
   cin>>b[i];
   q2.push({i,b[i]});
  }
  int cnt=0,rem=k-l;
  for(int i=1;i<=n;i++)
   q3.push({i,a[i]+b[i]});
  
  while(cnt<k)
  {
   //free flow
   if(rem)
   {
    while(vis1[q1.top().id])
     q1.pop();
    while(vis2[q2.top().id])
     q2.pop();
    int u=q1.top().id,v=q2.top().id;
    ans+=a[u]+b[v];
    vis1[u]=vis2[v]=1;
    cnt++;
    if(u!=v)
    {
     rem--;
     rem+=(vis1[u]&&vis2[u])+(vis1[v]&&vis2[v]);
    }
    if(!vis2[u])
     q4.push({u,b[u]});
    if(!vis1[v])
     q5.push({v,a[v]});
    q1.pop(),q2.pop();
    continue;
   }
   
   //add a pair directly
   int num1=0,id1=0;
   while(!q3.empty())
   {
    int id=q3.top().id,x=q3.top().x;
    if(vis1[id]||vis2[id])
     q3.pop();
    else
    {
     num1=x,id1=id;
     break;
    }
   }
   
   //pair a num in array a
   int num2=0,id2a=0,id2b=0;
   while(!q4.empty()&&vis2[q4.top().id])
    q4.pop();
   if(!q4.empty())
    id2b=q4.top().id,num2+=q4.top().x;
   while(vis1[q1.top().id])
    q1.pop();
   id2a=q1.top().id,num2+=q1.top().x;
   
   //pair a num in array b
   int num3=0,id3a=0,id3b=0;
   while(!q5.empty()&&vis1[q5.top().id])
    q5.pop();
   if(!q5.empty())
    id3a=q5.top().id,num3+=q5.top().x;
   while(vis2[q2.top().id])
    q2.pop();
   id3b=q2.top().id,num3+=q2.top().x;
   
   int maxa=max(num1,max(num2,num3));
   ans+=maxa;
   if(num2==num3&&maxa==num2)
   {
    if(vis2[id2a])
    {
     rem++;
     vis1[id2a]=1,q1.pop();
     vis2[id2b]=1,q4.pop();
    }
    else if(vis1[id3b])
    {
     rem++;
     vis2[id3b]=1,q2.pop();
     vis1[id3a]=1,q5.pop();
    }
    else
    {
     vis1[id2a]=1,q1.pop();
     vis2[id2b]=1,q4.pop();
     q4.push({id2a,b[id2a]});
    }
   }
   else if(maxa==num2)
   {
    vis1[id2a]=1,q1.pop();
    vis2[id2b]=1,q4.pop();
    if(vis2[id2a])rem++;
    else q4.push({id2a,b[id2a]});
   }
   else if(maxa==num3)
   {
    vis2[id3b]=1,q2.pop();
    vis1[id3a]=1,q5.pop();
    if(vis1[id3b])rem++;
    else q5.push({id3b,a[id3b]});
   }
   else if(maxa==num1)
   {
    vis1[id1]=vis2[id1]=1;
    q3.pop();
   }
   cnt++;
  }
  cout<<ans<<endl;
 }
 return 0;
}