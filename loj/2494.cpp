#include <iostream>
#include <string>
#include <algorithm>
#define MOD 1000000007
using namespace std;
struct node
{
 string s;
 int id;
 bool operator<(const node&a)const
 {
  return s>a.s||(s==a.s&&id<a.id);
 }
}p[5005];
string a[1005];
long long res[5005];
int main()
{
 ios::sync_with_stdio(false);
 int n,m,q;
 cin>>n>>m>>q;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 for(int i=0;i<m;i++)
 {
  p[i].id=i;
  for(int j=n;j;j--)
  {
   a[j][i]-='0';
   res[i]=(res[i]*2+a[j][i])%MOD;
   p[i].s.push_back(a[j][i]);
  }
 }
 p[m].id=m;
 p[m+1].id=m+1;
 for(int j=n;j;j--)
 {
  res[m]=(res[m]*2+1)%MOD;
  p[m].s.push_back(1);
 }
 res[m]++;
 sort(p,p+m+1);
 while(q--)
 {
  string str;
  cin>>str;
  int l=0,r=m+1;
  for(int i=m;i;i--)
   if(str[p[i].id]=='1')
   {
    l=i;
    break;
   }
  for(int i=0;i<=m;i++)
   if(str[p[i].id]=='0')
   {
    r=i;
    break;
   }
  cout<<(l>r?0:(res[p[l].id]-res[p[r].id]+MOD)%MOD)<<endl;
 }
 return 0;
}