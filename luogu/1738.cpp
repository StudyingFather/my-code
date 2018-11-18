#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
set<string> tr;
char s[105],s1[105];
int main()
{
 ios::sync_with_stdio(false);
 int n,ans=0;
 string r="/";
 tr.insert(r);
 cin>>n;
 while(n--)
 {
  memset(s,0,sizeof(s));
  memset(s1,0,sizeof(s1));
  cin>>s;
  int len=strlen(s);
  s1[0]='/';
  for(int i=0;i<len;i++)
   if(s[i]=='/')
   {
   	string lib=s1;
   	if(tr.count(lib))
	{
	 s1[i]=s[i];
	 continue;
	}
   	else
   	{
   	 for(int j=i;j<len;j++)
   	  if(s[j]=='/')
   	  {
   	   lib=s1;
   	   tr.insert(lib);
   	   ans++;
   	   s1[j]=s[j];
	  }
	  else s1[j]=s[j];
	 lib=s;
	 tr.insert(lib);
	 ans++;
	 break;
	}
   }
   else s1[i]=s[i];
  string lib=s;
  if(!tr.count(lib))
  {
   tr.insert(lib);
   ans++;
  }
  cout<<ans<<endl;
 }
 return 0;
}
