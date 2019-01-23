#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,int> ma;
int a[105][105],f[105][105];
int main()
{
 int n,m,ans=1;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
 {
  string s;
  cin>>s;
  ma[s]=i;
 }
 for(int i=1;i<=m;i++)
 {
  string s1,s2;
  cin>>s1>>s2;
  a[ma[s1]][ma[s2]]=a[ma[s2]][ma[s1]]=1;
 }
 f[1][1]=1;
 for(int i=1;i<n;i++)
  for(int j=i+1;j<=n;j++)
   for(int k=1;k<=n;k++)
    if(a[j][k]&&f[i][k])f[i][j]=f[j][i]=max(f[i][j],f[i][k]+1);
 for(int i=1;i<=n;i++)
  if(a[i][n])ans=max(ans,f[i][n]);
 cout<<ans<<endl;
 return 0;
}
