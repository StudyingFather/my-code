#include <iostream>
#include <algorithm>
using namespace std;
struct sweet
{
 long long w;
 int n;
}a[10005];
int cmp(const sweet&a,const sweet&b)
{
 return a.w<b.w||(a.w==b.w&&a.n<b.n);
}
int cmp2(const sweet&a,const sweet&b)
{
 return a.n<b.n;
}
long long b[10005];
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i].w;
  a[i].n=i;
 }
 sort(a+1,a+n+1,cmp);
 for(int i=1;i<=n;i++)
  b[i]=b[i-1]+a[i].w;
 long long total=b[n],diff=b[n];
 for(int i=1;i<=n;i++)
  if(abs(diff)<abs(total-2*b[i]))
  {
   sort(a+1,a+i,cmp2);
   for(int j=1;j<=i-1;j++)
    cout<<a[j].n<<endl;
   return 0;
  }
  else diff=total-2*b[i];
}
