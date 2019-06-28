#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int inf=0x3f3f3f;
int a[2005],b[2005],c[2005];
int n,m;
priority_queue<int>q;
void del()
{
 int i,j;
 for(i=0;i<n;++i)
  q.push(a[i]+b[0]);
 for(i=1;i<n;++i)
 {
  for(j=0;j<n;++j)
  {
   int x=a[j]+b[i];
   if(x<q.top())
   {
    q.pop();
    q.push(x);
   }
   else break;
  }
 }
 for(i=0; i<n; ++i)
 {
  a[n-1-i]=q.top();
  q.pop();
 }
}
int main()
{
 int t;
 int i,j;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d%d",&m,&n);
  for(j=0;j<n;++j)
   scanf("%d",&a[j]);
  sort(a,a+n);
  for(i=1;i<m;i++)
  {
   for(j=0;j<n;++j)
    scanf("%d",&b[j]);
   sort(b,b+n);
   del();
  }
  for(i=0;i<n-1;++i)
   printf("%d ",a[i]);
  printf("%d\n",a[n-1]);
 }
 return 0;
}
