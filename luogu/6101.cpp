#include <cstring>
#include <iostream>
using namespace std;
char s[1000005];
__int128 t[135];
int main()
{
 ios::sync_with_stdio(false);
 unsigned long long l0;
 cin>>s;
 cin>>l0;
 __int128 l=l0,len=strlen(s),maxt=0;
 int ans=0;
 for(int i=0;i<len;i++)
  t[s[i]]++;
 for(int i=0;i<128;i++)
  maxt=max(maxt,t[i]);
 while(len<l)
 {
  len+=maxt;
  maxt<<=1;
  ans++;
 }
 cout<<ans<<endl;
 return 0;
}