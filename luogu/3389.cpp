#include <cstdio>
#include <algorithm>
#define eqs 1e-8
using namespace std;
double mat[105][105],ans[105];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n+1;j++)
   scanf("%lf",&mat[i][j]);
 for(int i=1;i<=n;i++)
 {
  int maxr=i;
  for(int j=i+1;j<=n;j++)
   if(abs(mat[maxr][i])<abs(mat[j][i]))maxr=j;
  if(abs(mat[maxr][i])<eqs)
  {
   puts("No Solution");
   return 0;
  }
  if(i!=maxr)swap(mat[i],mat[maxr]);
  double tmp=mat[i][i];
  for(int j=i;j<=n+1;j++)
   mat[i][j]/=tmp;
  for(int j=i+1;j<=n;j++)
  {
   tmp=mat[j][i];
   for(int k=i;k<=n+1;k++)
    mat[j][k]-=mat[i][k]*tmp;
  }
 }
 for(int i=n;i;i--)
 {
  ans[i]=mat[i][n+1];
  for(int j=i+1;j<=n;j++)
   ans[i]-=mat[i][j]*ans[j];
 }
 for(int i=1;i<=n;i++)
  printf("%.2lf\n",ans[i]);
 return 0;
}