#include <cstdio>
#define MOD 1000000007
int s[1005][1005],a[1005][1005],n;
int sta[1005];
long long solve(int x,int k)
{
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   if(((a[i][j]>>k)&1)==x)s[i][j]=s[i-1][j]+1;
   else s[i][j]=0;
 long long ans=0;
 for(int i=1;i<=n;i++)
 {
  long long res=0;
  int top=0;
  for(int j=1;j<=n;j++)
  {
   res+=s[i][j];
   while(top&&s[i][sta[top]]>s[i][j])
   {
    res-=(sta[top]-sta[top-1])*(s[i][sta[top]]-s[i][j]);
    top--;
   }
   if(x)ans=(ans+(res<<k))%MOD;
   else ans=(ans+((i*j-res)<<k))%MOD;
   sta[++top]=j;
  }
 }
 return ans;
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   scanf("%d",&a[i][j]);
 long long ans1=0,ans2=0;
 for(int k=0;k<31;k++)
 {
  ans1=(ans1+solve(1,k))%MOD;
  ans2=(ans2+solve(0,k))%MOD;
 }
 printf("%d %d\n",(int)ans1,(int)ans2);
 return 0;
}