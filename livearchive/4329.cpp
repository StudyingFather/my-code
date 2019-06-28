#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int A[100005],C[100005];
long long c[20005],d[20005];
int lowbit(int x)
{
 return x&-x;
}
void add(int x,int d)
{
 while(x<100005)
 {
  C[x]+=d;
  x+=lowbit(x);
 }
}
int sum(int x)
{
 int ret=0;
 while(x>0)
 {
  ret+=C[x];
  x-=lowbit(x); 
 }
 return ret;
}
int num[20005];
int main()
{
 int T;
 cin>>T;
 while(T--)
 {
  int n;
  cin>>n;   
  memset(C,0,sizeof(C));
  for(int i=0;i<n;i++)
  {
   cin>>num[i];
   add(num[i],1);
   c[i]=sum(num[i])-1;  
  }
  memset(C,0,sizeof(C));
  for(int i=n-1;i>=0;i--)
  {
   add(num[i],1);
   d[i]=sum(num[i])-1;
  }
  long long ans=0;
  for(int i=0;i<n;i++)
   ans+=c[i]*(n-i-1-d[i])+(i-c[i])*d[i];
  cout<<ans<<endl;
 }
 return 0;
}
