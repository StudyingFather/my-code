#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> v;
int main()
{
 string s;
 int maxl=0,line=0,ans=0;
 while(getline(cin,s))
  if(s!="EOF")
  {
   string s1;
   int len=s.length();
   for(int i=0;i<len;i++)
    if(s[i]!='<')s1.push_back(s[i]);
    else if(s1.length())s1.pop_back();
   v.push_back(s1),maxl++;
  }
  else break;
 while(getline(cin,s))
 {
  if(s=="EOF")break;
  if(line>=maxl)continue;
  int len=s.length();
  string s1;
  for(int i=0;i<len;i++)
   if(s[i]!='<')s1.push_back(s[i]);
   else if(s1.length())s1.pop_back();
  len=min(s1.length(),v[line].length());
  for(int i=0;i<len;i++)
   if(v[line][i]==s1[i])ans++;
  line++;
 }
 int t;
 cin>>t;
 cout<<int(ans*60.0/t+0.5)<<endl;
 return 0;
}