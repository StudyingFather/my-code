#include <iostream>
#include <cstring>
using namespace std;
struct data
{
 int a[3][3];
}d[2][400005];
int xx[4]={1,-1,0,0},yy[4]={0,0,1,-1};
int mp[2][400005],step[2][400005],flag=0;
int t[2],w[2]={1,1};
void sp(int &a,int &b)
{
 int t=a;
 a=b;
 b=t;
}
bool pd(int x,int y)
{
 if(x>=3||y>=3||x<0||y<0)return 0;
 return 1;
}
const int fac[10]={1,1,2,6,24,120,720,5040,40320,362880};
int cantor(int x)
{
 int m[9];
 for(int i=9;i>=1;i--)
 {
  m[i]=x%10;
  x/=10;
 }
 int s=0;
 for(int i=1;i<=9;i++)
 {
  int temp=0;
  for(int j=i+1;j<=9;j++)
   if(m[j]<m[i])temp++;
  s+=fac[9-i]*temp;
 }
 return s;
}
int Hash(int a[3][3])
{
 int x=0,k=1;
 for(int i=2;i>=0;i--)
  for(int j=2;j>=0;j--)
  {
   x+=a[i][j]*k;
   k*=10;
  }
 return cantor(x);
}
void search(int k)
{
 for(int i=0;i<3;i++)
  for(int j=0;j<3;j++)
   d[k][w[k]].a[i][j]=d[k][t[k]].a[i][j];
 int x,y;
 for(int i=0;i<3;i++)
  for(int j=0;j<3;j++)
   if(d[k][t[k]].a[i][j]==0)
   {
    x=i;
    y=j;
    break;
   }
 for(int dir=0;dir<4;dir++)
 {
  for(int i=0;i<3;i++)
   for(int j=0;j<3;j++)
    d[k][w[k]].a[i][j]=d[k][t[k]].a[i][j];
  int p=x+xx[dir],q=y+yy[dir];
  if(pd(p,q))
  {
   sp(d[k][w[k]].a[x][y],d[k][w[k]].a[p][q]);
   int temp=Hash(d[k][w[k]].a);
   if(mp[k][temp]==-1)
   {
    step[k][w[k]]=step[k][t[k]]+1;
    mp[k][temp]=step[k][w[k]];
    if(mp[0][temp]!=-1&&mp[1][temp]!=-1)
    {
     cout<<mp[0][temp]+mp[1][temp];
     flag=1;
     return;
    }
    w[k]++;
   }
  }
 }
 t[k]++;
}
void doit()
{
 while(!flag)
 {
  if(w[0]-t[0]<=w[1]-t[1])search(0);
  else search(1);
 }
}
int main()
{
 string str;
 cin>>str;
 int k=0;
 for(int i=0;i<3;i++)
  for(int j=0;j<3;j++)
  {
   d[0][0].a[i][j]=str[k]-'0';
   k++;
  }
 d[1][0]=(data){1,2,3,8,0,4,7,6,5};
 memset(mp,-1,sizeof(mp));
 mp[0][Hash(d[0][0].a)]=mp[1][Hash(d[1][0].a)]=0;
 doit();
 return 0;
}
