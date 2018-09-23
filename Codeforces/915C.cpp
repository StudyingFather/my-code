#include <iostream>
using namespace std;
long long m[25],n[25],lena,lenb,t[25],ans,b1,solved=1;
long long pow_10(int k)
{
 long long ans=1;
 for(int i=1;i<=k;i++)
  ans*=10;
 return ans;
}
void dfs(int k)
{
 if(k==0&&ans<=b1&&solved)
 {
  cout<<ans;
  solved=0;
  return;
 }
 else
 {
  for(int i=9;i>=0;i--)
   if(!solved)return;
   else if(ans*pow_10(k)>b1)return;
   else if(t[i]&&(ans*10+i)*pow_10(k-1)<=b1)
   {
    t[i]--;
    ans*=10;
    ans+=i;
    dfs(k-1);
    ans-=i;
    ans/=10;
    t[i]++;
   }
 }
}
int main()
{
 long long a,b;
 cin>>a>>b;
 b1=b;
 while(b)
 {
  n[++lenb]=b%10;
  b/=10;
 }
 while(a)
 {
  t[a%10]++;
  a/=10;
  lena++;
 }
 dfs(lena);
 return 0;
}
