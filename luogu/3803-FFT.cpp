#include <cstdio>
#include <cmath>
#include <algorithm>
#define PI 3.1415926535897
using namespace std;
struct complex
{
 double x,y;
 complex(double a=0,double b=0)
 {
  x=a,y=b;
 }
}a[4000005],b[4000005];
int r[4000005],n,m;
complex operator+(complex a,complex b)
{
 return complex(a.x+b.x,a.y+b.y);
}
complex operator-(complex a,complex b)
{
 return complex(a.x-b.x,a.y-b.y);
}
complex operator*(complex a,complex b)
{
 return complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}
void fft(complex *f,int op)
{
 for(int i=0;i<n;i++)
  if(i<r[i])swap(f[i],f[r[i]]);
 for(int i=2;i<=n;i<<=1)
 {
  int len=i>>1;
  complex tmp(cos(PI/len),op*sin(PI/len));
  for(int j=0;j<n;j+=i)
  {
   complex tmp1(1,0);
   for(int k=j;k<j+len;k++)
   {
    complex x=tmp1*f[len+k];
    f[len+k]=f[k]-x;
    f[k]=f[k]+x;
    tmp1=tmp1*tmp;
   }
  }
 }
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=0;i<=n;i++)
  scanf("%lf",&a[i].x);
 for(int i=0;i<=m;i++)
  scanf("%lf",&b[i].x);
 m+=n,n=1;
 while(n<=m)
  n<<=1;
 for(int i=0;i<n;i++)
  r[i]=(r[i>>1]>>1)|((i&1)?n>>1:0);
 fft(a,1);
 fft(b,1);
 for(int i=0;i<n;i++)
  a[i]=a[i]*b[i];
 fft(a,-1);
 for(int i=0;i<=m;i++)
  printf("%d ",(int)floor(fabs(a[i].x)/n+0.5));
 return 0;
}