#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[100005],b[100005],n;
bool cmp(int a,int b)
{
 return a>b;
}
int main()
{
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 sort(a+1,a+1+n,cmp);
 memcpy(b,a,sizeof(b));
 int ans=0;
 int ii=n,jj=n;
 for(int i=1,j=1;i<=ii;)
 {
  if(b[i]>a[j])
  {
   ans++;
   i++;
   j++;
  }
  else if(b[i]<a[j])
  {
   j++;
   ii--;
  }
  else
  {
   if(b[ii]>a[jj])
   {
    ans++;
    ii--;
    jj--;
   }
   else
   {
    ii--;
    j++;
   }
  }
 }
 cout<<ans;
 return 0;
}
