/*
 Name: luogu P2814
 Author: StudyingFather
 Date: 2019/08/18 16:59
 Website: https://studyingfather.com
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
string s;
char c;
int fa[50005],cnt,f;
map<string,int> ma1;
map<int,string> ma2;
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
 while(cin>>c)
 {
  if(c=='$')return 0;
  cin>>s;
  if(!ma1[s])
  {
   ma1[s]=++cnt;
   ma2[cnt]=s;
   fa[cnt]=cnt;
  }
  if(c=='#')f=ma1[s];
  else if(c=='+')fa[ma1[s]]=f;
  else cout<<s<<' '<<ma2[find(ma1[s])]<<endl;
 }
 return 0;
}