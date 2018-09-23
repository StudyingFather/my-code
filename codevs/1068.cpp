#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a,b,c,d,s[350],f[45][45][45][45];
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=0;i<n;i++)
  scanf("%d",&s[i]);
 for(int i=1;i<=m;i++)
 {
  int num;
  scanf("%d",&num);
  if(num==1)a++;
  else if(num==2)b++;
  else if(num==3)c++;
  else d++;
 }
 for(int i=0;i<=a;i++)
  for(int j=0;j<=b;j++)
   for(int k=0;k<=c;k++)
    for(int l=0;l<=d;l++)
    {
     if(i)f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l]);
     if(j)f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k][l]);
     if(k)f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k-1][l]);
	   if(l)f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k][l-1]);
	   f[i][j][k][l]+=s[i+2*j+3*k+4*l];
	  }
 printf("%d",f[a][b][c][d]);
 return 0;
}
