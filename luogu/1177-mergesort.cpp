#include <iostream>
using namespace std;
int a[100005],b[100005];
void mergesort(int l,int r)
{
 if(l==r)return;
 int mid=l+(r-l)/2;
 mergesort(l,mid);
 mergesort(mid+1,r);
 int p=l,q=mid+1,t=l;
 while(t<=r)
 {
  if(p<=mid&&(q>r||a[p]<=a[q]))
   b[t++]=a[p++];
  else
   b[t++]=a[q++];
 }
 for(int i=l;i<=r;i++)
  a[i]=b[i];
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 mergesort(1,n);
 for(int i=1;i<=n;i++)
  cout<<a[i]<<' ';
 return 0;
}