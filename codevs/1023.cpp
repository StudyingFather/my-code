#include <cstdio>
using namespace std;
double GPA,total,a,b;
int n;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%lf%lf",&a,&b);
  total+=a;
  GPA+=a*b;
 }
 GPA/=total;
 printf("%.2lf",GPA);
 return 0;
}
