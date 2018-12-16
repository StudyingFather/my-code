#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[110];
bool v[110][110];
int f[110][110];
bool judge(int l,int r,int cl,int cr)
{
 int clen=cr-cl+1,len=r-l+1;
 if(len%clen)return false;
 for(int i=l;i<=r;i++)
  if(s[i]!=s[(i-l)%clen+cl])return false;
 return true;
}
int get(int x)
{
 int t=0;
 while(x)
 {
  x/=10;
  t++;
 }
 return t;
}
int dp(int l,int r)
{
 if(l==r)return 1;
 if(v[l][r])return f[l][r];
 v[l][r]=1;
 int len=r-l+1;
 for(int i=l;i<r;i++)
 {
  len=min(len,dp(l,i)+dp(i+1,r));
  if(judge(i+1,r,l,i))len=min(len,dp(l,i)+2+get((r-i)/(i-l+1)+1));
 }
 return f[l][r]=len;
}
int main()
{
 scanf("%s",s);
 printf("%d",dp(0,strlen(s)-1)); 
 return 0;
}
