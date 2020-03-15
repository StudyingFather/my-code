#include <cstring>
#include <iostream>
using namespace std;
char s[200005];
long long t[35];
int main()
{
 cin>>s;
 long long n=strlen(s);
 long long ans=1+n*(n-1)/2;
 for(int i=0;i<n;i++)
  t[s[i]-'a']++;
 for(int i=0;i<26;i++)
  ans-=t[i]*(t[i]-1)/2;
 cout<<ans<<endl;
 return 0;
}