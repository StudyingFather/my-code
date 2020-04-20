#include <iostream>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n;
  bool flag=true;
  cin>>n;
  int lastp=0,lastc=0;
  for(int i=1;i<=n;i++)
  {
   int p,c;
   cin>>p>>c;
   if(p<c)
    flag=false;
   if(lastp>p||lastc>c)
    flag=false;
   if(p-lastp<c-lastc)
    flag=false;
   lastp=p,lastc=c;
  }
  cout<<(flag?"YES":"NO")<<endl;
 }
 return 0;
}