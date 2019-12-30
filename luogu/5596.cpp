#include <cmath>
#include <iostream>
using namespace std;
int main()
{
 long long a,b,ans=0;
 cin>>a>>b;
 if(a*a==4*b)
 {
  cout<<"inf"<<endl;
  return 0;
 }
 long long tmp=sqrt(b);
 if(tmp*tmp==b)ans++;
 for(long long i=1;;i++)
 {
  long long x=2*i-a,y=b-i*i;
  if(((x>0&&y>0)||(x<0&&y<0))&&y%x==0)ans++;
  if(x>0&&y<0)break;
 }
 cout<<ans<<endl;
 return 0;
}