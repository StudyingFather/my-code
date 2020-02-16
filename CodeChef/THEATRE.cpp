#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[5][5],res1[5],res2[5],vis1[5],vis2[5],res;
void dfs(int d)
{
 if(d==5)
 {
  int tmp=0;
  for(int i=1;i<=4;i++)
  {
   if(!a[res1[i]][res2[i]])tmp-=100;
   else tmp+=i*25*a[res1[i]][res2[i]];
  }
  res=max(tmp,res);
  return;
 }
 for(int i=1;i<=4;i++)
  for(int j=1;j<=4;j++)
   if(!vis1[i]&&!vis2[j])
   {
    vis1[i]=1,vis2[j]=1;
    res1[d]=i,res2[d]=j;
    dfs(d+1);
    res1[d]=0,res2[d]=0;
    vis1[i]=0,vis2[j]=0;
   }
}
int main()
{
 int t,ans=0;
 cin>>t;
 while(t--)
 {
  res=-400;
  memset(a,0,sizeof(a));
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
   string s;
   int num,x,y;
   cin>>s>>num;
   x=s[0]-'A'+1;
   y=num/3;
   a[x][y]++;
  }
  dfs(1);
  cout<<res<<endl;
  ans+=res;
 }
 cout<<ans<<endl;
 return 0;
}