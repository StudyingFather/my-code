// Problem : #3011. 「JOI 2019 Final」画展
// Contest : LibreOJ
// URL : https://loj.ac/problem/3011
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 int s,v;
}a[100005];
int c[100005];
bool cmp(const node&a,const node&b)
{
 return a.v<b.v||(a.v==b.v&&a.s<b.s);
}
int main()
{
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  cin>>a[i].s>>a[i].v;
 for(int i=1;i<=m;i++)
  cin>>c[i];
 sort(a+1,a+n+1,cmp);
 sort(c+1,c+m+1);
 int last=1e9+7,ans=0;
 for(int i=m,j=n;i;i--)
 {
  bool flag=false;
  while(j)
  {
   if(a[j].s<=c[i]&&a[j].v<=last)
    last=a[j].v,flag=true;
   j--;
   if(flag)break;
  }
  ans+=flag;
 }
 cout<<ans<<endl;
 return 0;
}