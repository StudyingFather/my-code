#include <cstdio>
#define MOD 1000000
int f[2][45][45][45][5][5];
int a[5];
bool check(int i,int j,int k,int l,int m,int n)
{
 static int tmp[5];
 tmp[0]=i,tmp[1]=j,tmp[2]=k,tmp[3]=l;
 for(int i=0;i<=3;i++)
  if(tmp[i]==0&&(m==i||n==i))return false;
 return true;
}
bool get(int x,int y)
{
 return x&(1<<y);
}
bool check(int i,int j,int k,int l,int m,int n,int o)
{
 static int tmp[5];
 tmp[0]=i,tmp[1]=j,tmp[2]=k,tmp[3]=l;
 tmp[o]++;
 for(int i=0;i<=3;i++)
  if(tmp[i]>a[i])return false;
 for(int i=0;i<=1;i++)
  if(get(m,i)==get(n,i)&&get(n,i)==get(o,i)&&m!=4)return false;
 return true;
}
void calc(int i,int j,int k,int l,int m,int n,int o)
{
 static int tmp[5];
 tmp[0]=i,tmp[1]=j,tmp[2]=k,tmp[3]=l;
 int res=f[i&1][j][k][l][m][n];
 tmp[o]++;
 int&p=f[tmp[0]&1][tmp[1]][tmp[2]][tmp[3]][n][o];
 p+=res;
 if(p>=MOD)p-=MOD;
}
void clear(int i)
{
 for(int j=0;j<=a[1];j++)
  for(int k=0;k<=a[2];k++)
   for(int l=0;l<=a[3];l++)
    for(int m=0;m<=4;m++)
     for(int n=0;n<=4;n++)
      f[i][j][k][l][m][n]=0;
}
int main()
{
 for(int i=0;i<=3;i++)
  scanf("%d",&a[i]);
 f[0][0][0][0][4][4]=1;
 for(int i=0;i<=a[0];i++)
 {
  clear(!(i&1));
  for(int j=0;j<=a[1];j++)
   for(int k=0;k<=a[2];k++)
    for(int l=0;l<=a[3];l++)
     for(int m=0;m<=4;m++)
      for(int n=0;n<=4;n++)
      {
       int p=i+j+k+l;
       if((p==0&&(m!=4||n!=4))||(p==1&&m!=4))continue;
       if(p>=2&&(m==4||n==4))continue;
       if(!check(i,j,k,l,m,n))continue;
       for(int o=0;o<=3;o++)
        if(check(i,j,k,l,m,n,o))
         calc(i,j,k,l,m,n,o);
      }
 }
 int ans=0;
 for(int i=0;i<=4;i++)
  for(int j=0;j<=4;j++)
   ans+=f[a[0]&1][a[1]][a[2]][a[3]][i][j];
 printf("%d\n",ans%MOD);
 return 0;
}