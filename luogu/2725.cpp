/*
 Name: luogu P2725
 Author: StudyingFather
 Date: 2019/08/24 15:54
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
int a[55],f[2000005];
queue<int> q;
int main()
{
 int k,n;
 scanf("%d%d",&k,&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 memset(f,-1,sizeof(f));
 f[0]=0;
 q.push(0);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  if(f[u]==k)continue;
  for(int i=1;i<=n;i++)
   if(f[u+a[i]]==-1)
   {
    f[u+a[i]]=f[u]+1;
    q.push(u+a[i]);
   }
 }
 for(int i=1;;i++)
  if(f[i]==-1)
  {
   printf("%d\n",i-1);
   return 0;
  }
}