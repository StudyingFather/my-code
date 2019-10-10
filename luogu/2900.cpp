/*
 Name: luogu P2900
 Author: StudyingFather
 Date: 2019/10/10 18:27
 Website: https://studyingfather.com
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 long long x,y;
}a[50005];
long long f[50005];
int q[50005];
bool cmp(const node&a,const node&b)
{
 return a.x>b.x||(a.x==b.x&&a.y>b.y);
}
double slope(int x,int y)
{
 return double(f[x]-f[y])/(a[y+1].x-a[x+1].x);
}
int main()
{
 int n,cnt=0;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i].x>>a[i].y;
 sort(a+1,a+n+1,cmp);
 for(int i=1;i<=n;i++)
  if(a[cnt].y<a[i].y)a[++cnt]=a[i];
 int l=0,r=0;
 for(int i=1;i<=cnt;i++)
 {
  while(l<r&&slope(q[l],q[l+1])<=a[i].y)
   l++;
  f[i]=f[q[l]]+a[q[l]+1].x*a[i].y;
  while(l<r&&slope(q[r-1],q[r])>=slope(q[r],i))
   r--;
  q[++r]=i;
 }
 cout<<f[cnt]<<endl;
 return 0;
}