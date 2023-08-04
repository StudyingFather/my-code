/*
 Name: Atcoder Beginner Contest 138E
 Author: StudyingFather
 Date: 2019/08/18 20:35
 Website: https://studyingfather.com
*/
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
char s[100005],t[100005];
vector<int> a[35];
int main()
{
 cin>>(s+1);
 cin>>(t+1);
 int lens=strlen(s+1),lent=strlen(t+1);
 for(int i=1;i<=lens;i++)
  a[s[i]-'a'].push_back(i);
 for(int i=1;i<=lent;i++)
  if(a[t[i]-'a'].empty())
  {
   cout<<-1<<endl;
   return 0;
  }
 int cur=0,cnt=0;
 for(int i=1;i<=lent;i++)
 {
  int num=t[i]-'a';
  auto tmp=upper_bound(a[num].begin(),a[num].end(),cur);
  if(tmp==a[num].end())
  {
   cnt++;
   cur=*a[num].begin();
  }
  else cur=*tmp;
 }
 cout<<1ll*cnt*lens+cur<<endl;
 return 0;
}
