#include <iostream>
#include <algorithm>
#include <cstring>
#define MOD 1000000007
using namespace std;
struct mat
{
 long long x[35][35];
 mat()
 {
  memset(x,0,sizeof(x));
 }
}base;
char s[100005];
mat operator*(mat a,mat b)
{
 mat ans;
 for(int k=1;k<=26;k++)
  for(int i=1;i<=26;i++)
   for(int j=1;j<=26;j++)
    ans.x[i][j]=(ans.x[i][j]+a.x[i][k]*b.x[k][j])%MOD;
 return ans;
}
mat fpow(mat a,long long b)
{
 mat ans;
 for(int i=1;i<=26;i++)
  ans.x[i][i]=1;
 while(b)
 {
  if(b&1)ans=ans*a;
  a=a*a;
  b>>=1;
 }
 return ans;
}
int main()
{
 long long n,ans=0;
 cin>>n;
 cin>>s;
 int len=strlen(s);
 for(int i=1;i<=26;i++)
  for(int j=1;j<=26;j++)
   base.x[i][j]=1;
 for(int i=1;i<len;i++)
  base.x[s[i-1]-'a'+1][s[i]-'a'+1]=0;
 mat res=fpow(base,n-1);
 for(int i=1;i<=26;i++)
  for(int j=1;j<=26;j++)
   ans=(ans+res.x[i][j])%MOD;
 cout<<ans<<endl;
 return 0;
}