#include <iostream>
#include <string>
#include <set>
using namespace std;
int ans;
set<string> s1,s2;
string str;
string init(string str)
{
 string t;
 for(auto c:str)
  if(c=='.'||c==',')
  {
   if(s1.count(t))s2.insert(t);
   if(c=='.')ans+=s2.size(),s2.clear();
   t.clear();
  }
  else if(c>='A'&&c<='Z')
   t.push_back(c+32);
  else t.push_back(c);
 if(s1.count(t))s2.insert(t);
 return t;
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>str;
  str=init(str);
  s1.insert(str);
 }
 while(cin>>str)
  init(str);
 cout<<ans<<endl;
 return 0;
}