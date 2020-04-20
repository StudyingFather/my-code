#include <iostream>
using namespace std;
int a[100005];
int main()
{
 int b,k;
 cin>>b>>k;
 for(int i=1;i<=k;i++)
  cin>>a[i];
 int ans=a[k]%2,num=1;
 for(int i=k-1;i;i--)
 {
  num=num*b%2;
  ans=(ans+num*a[i])%2;
 }
 if(ans==1)cout<<"odd"<<endl;
 else cout<<"even"<<endl;
 return 0;
}