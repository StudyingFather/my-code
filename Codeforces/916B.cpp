#include <iostream>
using namespace std;
long long a[255],len=99,e1;
void calc(long long num)
{
 while(num)
 {
  a[++len]=num%2;
  if(num%2==1)e1++;
  num/=2;
 }
}
int main()
{
 ios::sync_with_stdio(false);
 long long n,k;
 cin>>n>>k;
 calc(n);
 if(e1>k)
 {
  cout<<"NO";
  return 0;
 }
 else
  while(e1<k)
  {
   a[len-1]+=2;
   a[len]--;
   if(a[len]==0)len--;
   e1++;
  }
 cout<<"YES"<<endl;
 for(int i=len;i>=0;i--)
  for(int j=a[i];j>0;j--)
   cout<<i-100<<' ';
 return 0;
}
