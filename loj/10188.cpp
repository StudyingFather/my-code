#include <iostream>
using namespace std;
long long s[50005],q[50005],f[50005],l,r,n,len;
long long a(int x)
{
 return s[x]+x;
}
long long b(int x)
{
 return s[x]+x+1+len;
}
double slope(int x,int y)
{
 long long bx=b(x),by=b(y);
 return double(f[x]+bx*bx-f[y]-by*by)/(bx-by);
}
int main()
{
 cin>>n>>len;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  s[i]=s[i-1]+x;
 }
 for(int i=1;i<=n;i++)
 {
  while(l<r&&slope(q[l+1],q[l])<=2*a(i))
   l++;
  f[i]=f[q[l]]+(a(i)-b(q[l]))*(a(i)-b(q[l]));
  while(l<r&&slope(q[r],q[r-1])>slope(i,q[r]))
   r--;
  q[++r]=i;
 }
 cout<<f[n]<<endl;
 return 0;
}