#include <iostream>
using namespace std;
int main()
{
 int n;
 cin>>n;
 if(n<=20)
 {
  if(n==2||n==3||n==4||n==5||n==6||n==8||n==12)
   cout<<"YES"<<endl;
  else
   cout<<"NO"<<endl;
 }
 else
 {
  int x=n/10,y=n%10;
  if(x==2||x==7||x==9||y==1||y==7||y==9)
   cout<<"NO"<<endl;
  else
   cout<<"YES"<<endl;
 }
 return 0;
}