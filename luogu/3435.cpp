#include <iostream>
#include <algorithm>
using namespace std;
char s[1000005];
int nxt[1000005];
int main()
{
 long long n,ans=0;
 cin>>n;
 cin>>(s+1);
 nxt[1]=0;
 for(int i=2,j=0;i<=n;i++)
 {
  while(j&&s[i]!=s[j+1])
   j=nxt[j];
  if(s[i]==s[j+1])j++;
  nxt[i]=j;
 }
 for(int i=2,j=2;i<=n;i++,j=i)
 {
  while(nxt[j])j=nxt[j];
  if(nxt[i])nxt[i]=j;
  ans+=i-j;
 }
 cout<<ans<<endl;
 return 0;
}