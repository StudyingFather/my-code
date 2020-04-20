#include <iostream>
#include <algorithm>
using namespace std;
int a[100005],b[100005],c[100005],d[100005];
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 for(int i=1;i<=n;i++)
  cin>>b[i];
 if(a[1]!=b[1]||a[n]!=b[n])
 {
  cout<<"No"<<endl;
  return 0;
 }
 for(int i=1;i<n;i++)
 {
  c[i]=a[i+1]-a[i];
  d[i]=b[i+1]-b[i];
 }
 sort(c+1,c+n);
 sort(d+1,d+n);
 for(int i=1;i<n;i++)
  if(c[i]!=d[i])
  {
   cout<<"No"<<endl;
   return 0;
  }
 cout<<"Yes"<<endl;
 return 0;
}