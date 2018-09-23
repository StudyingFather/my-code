#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int l,r,a[100];
bool p[100000001];
void make()
{
 p[1]=0;
 int q=(int)sqrt(r);
 for(int i=2;i<=q;i++)
  if(p[i])
   for(int j=2;j<=r/i;j++)
    p[i*j]=0;
}
bool pd(int x)
{
 int q=(int)sqrt(x);
 for(int i=2;i<=q;i++)
  if(x%i==0)return 0;
 return 1;
}
void tab(int n,int t)
{
 if(t>(n+1)/2)
 {
  int s=0;
  for(int i=1;i<=n/2;i++)
   a[n-i+1]=a[i];
  for(int i=1;i<=n;i++)
   s=s*10+a[i];
  if(s>r||s<l)return;
  if(pd(s))cout<<s<<endl;
 } 
 else
  for(int i=(t==1);i<=9;i+=(t==1)+1)
  {
   a[t]=i;
   tab(n,t+1);
  }
}
int main()
{
 cin>>l>>r;
 memset(p,1,sizeof(p));
 for(int i=ceil(log10(l));i<=ceil(log10(r));i++)
  tab(i,1);
 return 0;
}
