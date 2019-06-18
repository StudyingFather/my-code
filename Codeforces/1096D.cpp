#include <iostream>
#include <algorithm>
#define INF (1ll<<62)
using namespace std;
long long f[5],n;
char s[100005];
const char t[]="hard";
int main()
{
 cin>>n;
 cin>>s;
 for(int i=0;i<n;i++)
 {
  int x;
  cin>>x;
  if(s[i]=='h')f[1]+=x;
  else if(s[i]=='a')f[2]=min(f[1],f[2]+x);
  else if(s[i]=='r')f[3]=min(f[2],f[3]+x);
  else if(s[i]=='d')f[4]=min(f[3],f[4]+x);
 }
 cout<<f[4]<<endl;
 return 0;
}