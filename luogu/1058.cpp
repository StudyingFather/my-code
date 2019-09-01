#include <cstdio>
#include <iostream>
using namespace std;
const char block[][15]=
{
 "..+---+",
 "./   /|",
 "+---+ |",
 "|   | +",
 "|   |/.",
 "+---+.."
};
int a[55][55],n,m,maxx,maxy;;
char res[1005][1005];
void draw(int x,int y) 
{
 for(int i=0;i<6;i++)
  for(int j=0;j<7;j++)
   if(block[6-i-1][j]!='.')res[x-i][y+j]=block[6-i-1][j]; 
}
int main()
{
 scanf("%d%d",&n,&m);
 maxy=4*m+2*n+1;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
   scanf("%d",&a[i][j]);
   maxx=max(maxx,a[i][j]*3+2*(n-i+1)+1); 
  }
 for(int i=1;i<=maxx;i++)
  for(int j=1;j<=maxy;j++)
   res[i][j]='.'; 
 for(int i=1;i<=n;i++)    
  for(int j=1;j<=m;j++)
  {
   int x=maxx-2*(n-i),y=2*(n-i)+4*(j-1)+1; 
   for(int k=1;k<=a[i][j];k++)
   {
    draw(x,y); 
    x-=3; 
   }
  }
 for(int i=1;i<=maxx;i++)
  puts(res[i]+1);
 return 0;
}