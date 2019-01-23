#include <iostream>
#include <set>
#include <string>
using namespace std;
set<string> se[1005];
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int l;
  cin>>l;
  for(int j=1;j<=l;j++)
  {
   string s;
   cin>>s;
   se[i].insert(s);
  }
 }
 int m;
 cin>>m;
 for(int i=1;i<=m;i++)
 {
  string s;
  cin>>s;
  for(int j=1;j<=n;j++)
   if(se[j].count(s))cout<<j<<' ';
  cout<<endl;
 }
 return 0;
} 
