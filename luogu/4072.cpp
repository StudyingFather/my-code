// Problem : P4072 [SDOI2016]征途
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P4072
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
using namespace std;
int s[3005],f[3005],g[3005],q[3005];
double slope(int x,int y)
{
 return 1.0*(g[x]-g[y]+s[x]*s[x]-s[y]*s[y])/(s[x]-s[y]);
}
int main()
{
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
 {
  cin>>s[i];
  s[i]+=s[i-1];
  g[i]=s[i]*s[i];
 }
 for(int p=1;p<m;p++)
 {
  memset(q,0,sizeof(q));
  int l=0,r=0;
  for(int i=1;i<=n;i++)
  {
   while(l<r&&slope(q[l],q[l+1])<2*s[i])
    l++;
   int x=s[i]-s[q[l]];
   f[i]=g[q[l]]+x*x;
   while(l<r&&slope(q[r-1],q[r])>slope(q[r],i))
    r--;
   q[++r]=i;
  }
  memcpy(g,f,sizeof(g));
 }
 cout<<f[n]*m-s[n]*s[n]<<endl;
 return 0;
}