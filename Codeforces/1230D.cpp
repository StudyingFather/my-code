/*
 Name: Codeforces 1230D
 Author: StudyingFather
 Date: 2019/09/25 22:39
 Website: https://studyingfather.com
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 long long a,b;
}p[7005];
long long ans=0;
int vis[7005];
bool cmp(const node&a,const node&b)
{
 return a.a>b.a||(a.a==b.a&&(a.b>b.b));
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>p[i].a;
 for(int i=1;i<=n;i++)
  cin>>p[i].b;
 sort(p+1,p+n+1,cmp);
 for(int i=1;i<=n;i++)
 {
  if(p[i].a==p[i+1].a&&i!=n)
   vis[i]=vis[i+1]=1;
  if(vis[i])ans+=p[i].b;
 }
 for(int i=1;i<=n;i++)
  if(!vis[i])
   for(int j=1;j<i;j++)
    if(vis[j]&&(p[j].a|p[i].a)==p[j].a)
    {
     ans+=p[i].b;
     vis[i]=1;
     break;
    }
 cout<<ans<<endl;
 return 0;
}