#include <iostream>
#include <cstring>
using namespace std;
char s[105];
int main()
{
 long long k;
 cin>>s;
 cin>>k;
 if(k==1)cout<<s[0];
 else
 {
  int len=strlen(s);
  for(int i=0;i<len;i++)
   if(s[i]=='1')
   {
    if(k==i+1)
    {
     cout<<1;
     break;
    }
   }
   else
   {
    cout<<s[i];
    break;
   }
 }
 return 0;
}
