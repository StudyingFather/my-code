#include <iostream>
using namespace std;
int t[15];
int main()
{
 ios::sync_with_stdio(false);
 int n,ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  t[x%10]++;
  ans=(ans+x)%10;
 }
 for(int i=0;i<=9;i++)
  for(int j=i+1;j<=9;j++)
   if(t[i]&&t[j]&&(i+j)%10==ans)
   {
    cout<<(!ans?10:ans)<<endl;
    return 0;
   }
 for(int i=0;i<=9;i++)
  if(t[i]>=2&&(i+i)%10==ans)
  {
   cout<<(!ans?10:ans)<<endl;
   return 0;
  }
 cout<<0<<endl;
 return 0;
}