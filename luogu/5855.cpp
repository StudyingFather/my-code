#include <cstring>
#include <iostream>
#include <set>
using namespace std;
int n,k;
set<int> s[25];
char str[25],ans[25];
bool check(char* str)
{
 for(int i=0;i<n;i++)
  if(!s[i].count(str[i]))return false;
 return true;
}
int main()
{
 cin>>n>>k;
 cin>>ans;
 long long cnt=1;
 for(int i=0;i<n;i++)
 {
  int v;
  cin>>v;
  cin>>str;
  cnt*=v;
  for(int j=0;j<v;j++)
   s[i].insert(str[j]);
 }
 for(int i=1;i<=k;i++)
 {
  cin>>str;
  if(check(str))cnt--;
  if(!strcmp(ans,str))
  {
   cout<<0<<endl;
   return 0;
  }
 }
 if(!check(ans))cout<<-1<<endl;
 else cout<<cnt<<endl;
 return 0;
}