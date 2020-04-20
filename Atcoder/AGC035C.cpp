#include <iostream>
using namespace std;
int main()
{
 int n;
 cin>>n;
 if((n&(n-1))==0)cout<<"No"<<endl;
 else
 {
  cout<<"Yes"<<endl;
  cout<<"1 2"<<endl;
  cout<<"2 3"<<endl;
  cout<<"3 "<<n+1<<endl;
  cout<<n+1<<" "<<n+2<<endl;
  cout<<n+2<<" "<<n+3<<endl;
  for(int i=2;2*i+1<=n;i++)
  {
   cout<<1<<" "<<2*i<<endl;
   cout<<1<<" "<<2*i+1<<endl;
   cout<<2*i<<" "<<2*i+n+1<<endl;
   cout<<2*i+1<<" "<<2*i+n<<endl;
  }
  if(n%2==0)
  {
   for(int i=2;i<=n;i++)
   {
    int p=i^n^1;
    if(p>1&&p<n&&i!=3&&p!=3)
    {
     cout<<i<<" "<<n<<endl;
     cout<<p<<" "<<2*n<<endl;
     break;
    }
   }
  }
 }
 return 0;
}