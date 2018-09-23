#include <stdio.h>
long long a[1001][1001];
int main()
{
 int x1,y1,x2,y2;
 scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
 x1+=2;y1+=2;x2+=2;y2+=2;   
 for(int i=2;i<=x1;i++)     
  for(int j=2;j<=y1;j++)
   {
    a[2][2]=1;
    a[x2][y2]=0;         
    a[x2+2][y2+1]=0;
    a[x2+1][y2+2]=0;
    a[x2-1][y2+2]=0;
    a[x2-2][y2+1]=0;
    a[x2-2][y2-1]=0;
    a[x2-1][y2-2]=0;
    a[x2+1][y2-2]=0;
    a[x2+2][y2-1]=0;
    a[i][j]=a[i-1][j]+a[i][j-1];
   }
 printf("%lld",a[x1][y1]);
 return 0;
}
