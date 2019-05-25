#include <iostream>
#include <cstring>
using namespace std;
char s1[55],s2[55];
int main()
{
 cin>>s1>>s2;
 int len=strlen(s1),ans=0;
 for(int i=0;i<len;i++)
  for(int j=1;j<len;j++)
   if(s1[i]==s2[j]&&s1[i+1]==s2[j-1])ans++;
 cout<<(1ll<<ans)<<endl;
 return 0;
}