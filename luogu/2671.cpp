#include<cstdio>
#include<cstring>
using namespace std;
long color[100005][3][2],number[100005],count[100005][2];
int main()
{
 int n,m,cor;
 long sum=0;
 scanf("%d%d",&n,&m);
 memset(count,0,sizeof(count));
 memset(color,0,sizeof(color));
 for(int i=1;i<=n;i++)
  scanf("%ld",&number[i]);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&cor);
  color[cor][0][i%2]+=i;
  color[cor][1][i%2]+=number[i];
  color[cor][2][i%2]+=number[i]*i;
  count[cor][i%2]++;
 }
 for(int i=1;i<=m;i++)
  for(int j=0;j<=1;j++)
   sum+=color[i][0][j]*color[i][1][j]+(count[i][j]-2)*color[i][2][j];
 sum%=10007;
 printf("%ld",sum);
 return 0;
}
