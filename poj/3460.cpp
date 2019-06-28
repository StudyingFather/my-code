#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n,a[20];
int sa[20];
bool judge()
{
 for(int i=0;i<n;i++)
  if(sa[i]!=a[i])return false;
 return true;
}
int h()
{
 int ret=0;
 for(int i=0;i<n-1;i++)
  if(a[i+1]!=a[i]+1)ret++;
 if(a[n-1]!=n)ret++;
 return ret;
}
bool dfs(int d,int maxd)
{
 if(judge())return true;
 if(3*d+h()>3*maxd)return false;
 int olda[20],b[20],tot;
 memcpy(olda,a,sizeof(a));
 for(int i=0;i<n;i++)
  for(int j=i;j<n;j++)
  {
   tot=0;
   for(int k=i;k<=j;k++)
    b[tot++]=olda[k];
   for(int k=0;k<n;k++)
   {
    memcpy(a,olda,sizeof(olda));
    if(k<i)
    {
     for(int u=0;u<i-k;u++)
      a[j-u]=a[i-u-1];
     for(int u=0;u<tot;u++)
      a[k+u]=b[u];
     if(dfs(d+1,maxd))return true;
    }
    else if(k>j)
    {
     for(int u=0;u<k-j;u++)
      a[i+u]=a[j+u+1];
     for(int u=0;u<tot;u++)
      a[i+k-j+u]=b[u];
     if(dfs(d+1,maxd))return true;
    }
   }
  }
 return false;
}
int IDAstar()
{
 if(judge())return 0;
 for(int i=1;i<=4;i++)
  if(dfs(0,i))return i;
 return 5;
}
int main()
{
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
   sa[i]=a[i];
  }
  sort(sa,sa+n);
  int ans=IDAstar();
  if(ans<=4)printf("%d\n",ans);
  else puts("5 or more");
 }
 return 0;
}
