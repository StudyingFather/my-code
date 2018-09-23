#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MOD 1000000007
using namespace std;
int a[1005],t[1005],f[1005][1005],b[1005];
int T,n,m;
void init()
{
 memset(f,0,sizeof(f));
 f[0][0]=1;
 sort(b+1,b+1+n);  
 int k=unique(b+1,b+1+n)-b-1;
 for(int i=1;i<=n;i++)  
  a[i]=lower_bound(b+1,b+1+k,a[i])-b+1; 
 a[0]=1;
}
inline int lowbit(int x)
{
 return x&-x;
}
inline void update(int x,int d)
{
 while(x<=n+1)
 {
  t[x]=(t[x]+d)%MOD;
  x+=lowbit(x);
 }
}
inline int query(int x)
{
 int res=0;
 while(x)
 {
  res=(res+t[x])%MOD;
  x-=lowbit(x);
 }
 return res%MOD;
}
int main()
{
 int ans;
 scanf("%d",&T);
 for(int l=1;l<=T;l++)
 {
  ans=0;
  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++)
  {
   scanf("%d",&a[i]);
   b[i]=a[i];
  }
  init();		
  f[0][0]=1;
  for(int i=1;i<=m;i++)
  {
   memset(t,0,sizeof(t));
   update(a[0],f[i-1][0]);
   for(int j=1;j<=n;j++)
   {
	f[i][j]=query(a[j]-1)%MOD;
	update(a[j],f[i-1][j]%MOD);
   }
  }
  for(int i=m;i<=n;i++)
   ans=(ans+f[m][i])%MOD;
  printf("Case #%d: %d\n",l,ans);
 }
 return 0;
}
