#include <iostream>
using namespace std;
long long a[2000005],b[2000005];
int main()
{
 long long k;
 int n=0;
 cin>>k;
 while(k)
 {
  n++;
  b[n]=(k-1)/(n+1)+1;
  k-=b[n];
 }
 for(int i=n;i;i--)
 {
  a[i]=i*b[i]-b[i+1];
  b[i]+=b[i+1];
 }
 int p=n;
 while(p)
 {
  int pos=1;
  while(a[pos])
   pos++;
  for(int i=1;i<pos;i++)
   a[i]--;
  a[pos]=pos;
  p--;
  if(pos>n)
  {
   p++;
   n++;
  }
 }
 cout<<n<<endl;
 for(int i=1;i<=n;i++)
  cout<<a[i]<<' ';
 return 0;
}