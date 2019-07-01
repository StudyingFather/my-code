#include <cstdio>
#include <cstring>
#include <algorithm>
int f[55][55],num[15],cnt;
using namespace std;
int calc(int n)
{
 if(!n)return 0;
 cnt=0;
 memset(num,0,sizeof(num)); 
 while(n)
 {
  num[++cnt]=n%10;
  n/=10;
 }
 int ans=0;
 for(int i=1;i<=cnt-1;i++)
  for(int j=1;j<=9;j++)
   ans+=f[i][j];
 for(int i=1;i<num[cnt];i++)
  ans+=f[cnt][i];
 for(int i=cnt-1;i>=1;i--)
 {
  for(int j=0;j<num[i];j++)
   if(abs(j-num[i+1])>=2)ans+=f[i][j];
  if(abs(num[i+1]-num[i])<2)break;
  if(i==1)ans++;
 }
 return ans;
}
int main()
{
 int a,b;
 scanf("%d%d",&a,&b);
 for(int i=0;i<=9;i++)
  f[1][i]=1;
 for(int i=2;i<=10;i++)
  for(int j=0;j<=9;j++)
   for(int k=0;k<=9;k++)
    if(abs(k-j)>=2)f[i][j]+=f[i-1][k];
 printf("%d",calc(b)-calc(a-1));
 return 0;
}