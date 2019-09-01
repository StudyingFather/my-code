/*
 Name: luogu P3661
 Author: StudyingFather
 Date: 2019/08/19 16:57
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct seg
{
 int l,r;
 bool operator<(const seg&a)const
 {
  return r>a.r;
 }
}s[20005];
int a[20005],vis[20005];
priority_queue<seg> q;
bool cmp(const seg&a,const seg&b)
{
 return a.l<b.l;
}
int main()
{
 int c,n;
 scanf("%d%d",&c,&n);
 for(int i=1;i<=c;i++)
  scanf("%d",&a[i]);
 sort(a+1,a+c+1);
 for(int i=1;i<=n;i++)
  scanf("%d%d",&s[i].l,&s[i].r);
 sort(s+1,s+n+1,cmp);
 int cur=1,ans=0;
 for(int i=1;i<=c;i++)
 {
  while(cur<=n&&s[cur].l<=a[i])
   q.push(s[cur++]);
  while(!q.empty()&&q.top().r<a[i])
   q.pop();
  if(!q.empty())ans++,q.pop();
 }
 printf("%d\n",ans);
 return 0;
}