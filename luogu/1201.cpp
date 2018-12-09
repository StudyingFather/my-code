#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,int> m;
struct people
{
 string name;
 int money;
}p[15];
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>p[i].name;
  m[p[i].name]=i;
 }
 for(int i=1;i<=n;i++)
 {
  string name;
  cin>>name;
  int x,y;
  cin>>x>>y;
  if(y==0)continue;
  p[m[name]].money-=x/y*y;
  for(int j=1;j<=y;j++)
  {
   cin>>name;
   p[m[name]].money+=x/y;
  }
 }
 for(int i=1;i<=n;i++)
  cout<<p[i].name<<' '<<p[i].money<<endl;
 return 0;
}
