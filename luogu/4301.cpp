#include <iostream>
#include <algorithm>
using namespace std;
int a[105],p[35];
bool cmp(int a,int b)
{
 return a>b;
}
bool find(int x)
{
 for(int i=30;i>=0;i--)
  if((x>>i)&1)
  {
   if(!p[i])break;
   else x^=p[i];
  }
 return x>0;
}
void add(int x)
{
 for(int i=30;i>=0;i--)
  if((x>>i)&1)
  {
   if(p[i])x^=p[i];
   else
   {
    p[i]=x;
    break;
   }
  }
}
int main()
{
 long long k,ans=0;
 cin>>k;
 for(int i=1;i<=k;i++)
  cin>>a[i];
 sort(a+1,a+k+1,cmp);
 for(int i=1;i<=k;i++)
  if(find(a[i]))add(a[i]);
  else ans+=a[i];
 cout<<ans<<endl;
 return 0;
}