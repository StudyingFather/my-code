#include <cstdio>
#include <cmath>
#include <algorithm>
#define PI 3.1415926535897
using std::swap;
using std::abs;
struct complex
{
 double x,y;
 complex(double a=0,double b=0)
 {
  x=a,y=b;
 }
}b[2000005],c[2000005];
int n,m,r[2000005];
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
 for(int p=2;p<=n;p<<=1)
 {
  int len=p>>1;
  complex omega1(cos(PI/len),op*sin(PI/len));
  for(int i=0;i<n;i+=p)
  {
   complex omega(1,0);
   for(int j=i;j<i+len;j++)
   {
    complex tmp=omega*f[len+j];
    f[len+j]=f[j]-tmp;
    f[j]=f[j]+tmp;
    omega=omega*omega1;
   }
  }
 }
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=0;i<=n;i++)
  scanf("%lf",&b[i].x);
 for(int i=0;i<=m;i++)
  scanf("%lf",&c[i].x);
 m+=n,n=1;
 while(n<=m)
  n<<=1;
 for(int i=0;i<n;i++)
  r[i]=(r[i>>1]>>1)|((i&1)?(n>>1):0);
 fft(b,1);
 fft(c,1);
 for(int i=0;i<n;i++)
  b[i]=b[i]*c[i];
 fft(b,-1);
 for(int i=0;i<=m;i++)
  printf("%.0lf ",abs(b[i].x)/n);
 return 0;
}