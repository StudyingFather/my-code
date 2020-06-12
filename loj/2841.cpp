// Problem : #2841. 「JOISC 2018 Day 4」图书馆
// Contest : LibreOJ
// URL : https://loj.ac/problem/2841
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "library.h"
#include <iostream>
using namespace std;
vector<int> q,ord,ans;
int dfs(int N,int x,int l,int r)
{
 if(l==r)return ord[l];
 int mid=(l+r)>>1;
 for(int i=0;i<N;i++)
  q[i]=0;
 for(int i=l;i<=mid;i++)
  q[ord[i]]=1;
 int res1=(mid-l+1)-Query(q);
 q[x]=1;
 int res2=(mid-l+2)-Query(q);
 if(res2>res1)return dfs(N,x,l,mid);
 else return dfs(N,x,mid+1,r);
}
void Solve(int N)
{
 for(int i=0;i<N;i++)
 {
  q.push_back(1);
  ord.push_back(i);
 }
 if(N==1)
 {
  ans.push_back(1);
  Answer(ans);
  return;
 }
 for(int i=0;i<N;i++)
 {
  q[i]=0;
  int res=Query(q);
  if(res==1)
  {
   ans.push_back(i);
   ord.erase(lower_bound(ord.begin(),ord.end(),i));
   break;
  }
  q[i]=1;
 }
 for(int i=1;i<N;i++)
 {
  int cur=dfs(N,ans[i-1],0,N-i-1);
  ans.push_back(cur);
  ord.erase(lower_bound(ord.begin(),ord.end(),cur));
 }
 for(int i=0;i<N;i++)
  ans[i]++;
 Answer(ans);
}