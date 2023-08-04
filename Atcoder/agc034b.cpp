#include <iostream>
#include <cstring>
using namespace std;
char s[200005];
int main()
{
 cin>>s;
 long long len=strlen(s),a=0,b=0,ans=0;
 for(int i=0;i<len;i++)
 {
  if(s[i]=='A'&&(!b))a++;
  else if(s[i]=='B'&&a&&(!b))b++;
  else if(s[i]=='C'&&a&&b)ans+=a,b=0;
  else
  {
   a=b=0;
   if(s[i]=='A')a++;
  }
 }
 cout<<ans<<endl;
 return 0;
}