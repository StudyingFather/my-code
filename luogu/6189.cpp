#include <iostream>
using namespace std;
long long f[100005];
int a(int x)
{
 return (3*x*x-x)/2;
}
int main()
{
 int n,p;
 cin>>n>>p;
 f[0]=1;
 for(int i=1;i<=n;i++)
  for(int j=1;;j++)
  {
   int x=a(j),y=a(-j);
   if(x<=i)
    f[i]=((f[i]+(j&1?1:-1)*f[i-x])%p+p)%p;
   if(y<=i)
    f[i]=((f[i]+(j&1?1:-1)*f[i-y])%p+p)%p;
   if(x>i||y>i)break;
  }
 cout<<f[n]<<endl;
 return 0;
}