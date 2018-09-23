#include <iostream>
#include <cstring>
using namespace std;
int an[200005];
long long ans=0;
void merge(int l,int m,int r)
{
 int a[100005],b[100005],temp[200005],tota=0,totb=0,tott=0;
 for(int i=l;i<=m;i++)
  a[++tota]=an[i];
 for(int i=m+1;i<=r;i++)
  b[++totb]=an[i];
 int aa=1,bb=1;
 while(aa<=tota&&bb<=totb)
 {
  if(a[aa]<=b[bb])temp[++tott]=a[aa++];
  else
  {
   ans+=tota-aa+1;
   temp[++tott]=b[bb++];
  }
 }
 while(aa<=tota)temp[++tott]=a[aa++];
 while(bb<=totb)temp[++tott]=b[bb++];
 for(int i=l,j=1;i<=r;i++,j++)
  an[i]=temp[j];
}
void mergesort(int l,int r)
{
 int m=(l+r)/2;
 if(l<r)
 {
  mergesort(l,m);
  mergesort(m+1,r);
  merge(l,m,r);
 }
} 
int main()
{
 int n,t;
 cin>>t;
 while(t--)
 {
  ans=0;
  memset(an,0,sizeof(an));
  cin>>n;
  for(int i=1;i<=n;i++)
   cin>>an[i];
  mergesort(1,n);
  cout<<ans<<endl;
 }
 return 0;
}
