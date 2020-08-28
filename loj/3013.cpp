// Problem : #3013. 「JOI 2019 Final」硬币收藏
// Contest : LibreOJ
// URL : https://loj.ac/problem/3013
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
using namespace std;
int ma[100005][5];
int main()
{
 ios::sync_with_stdio(false);
 int n;
 long long ans=0;
 cin>>n;
 for(int i=1;i<=2*n;i++)
 {
  int x,y;
  cin>>x>>y;
  if(x<1)ans+=1-x,x=1;
  else if(x>n)ans+=x-n,x=n;
  if(y<1)ans+=1-y,y=1;
  else if(y>2)ans+=y-2,y=2;
  ma[x][y]++;
 }
 int c1=0,c2=0;
 for(int i=1;i<=n;i++)
 {
  c1+=ma[i][1]-1,c2+=ma[i][2]-1;
  while(c1<0&&c2>0)
   c1++,c2--,ans++;
  while(c1>0&&c2<0)
   c1--,c2++,ans++;
  ans+=abs(c1)+abs(c2);
 }
 cout<<ans<<endl;
 return 0;
}