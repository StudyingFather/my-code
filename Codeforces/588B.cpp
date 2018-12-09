#include <iostream>
using namespace std;
int main()
{
 long long n,ans=1,cur=2;
 cin>>n;
 long long n1=n;
 while(n1!=1)
 {
  if(cur*cur>n)
  {
   ans*=n1;
   break;
  }
  bool flag=false;
  while(n1%cur==0)n1/=cur,flag=true;
  if(flag)ans*=cur;
  cur++;
 }
 cout<<ans<<endl;
 return 0;
}
