#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;
const char ma[][4]={"","","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
string num;
int len;
set<string> s;
bool flag;
void dfs(string str,int d)
{
 if(d==len)
 {
  if(s.count(str))
  {
   cout<<str<<endl;
   flag=true;
  }
  return;
 }
 for(int i=0;i<=2;i++)
  dfs(str+ma[(int)num[d]][i],d+1);
}
int main()
{
 cin>>num;
 len=num.length();
 for(int i=0;i<len;i++)
  num[i]-='0';
 for(int i=1;i<=4617;i++)
 {
  string dic;
  cin>>dic;
  s.insert(dic);
 }
 dfs("",0);
 if(!flag)cout<<"NONE"<<endl;
 return 0;
}
