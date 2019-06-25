#include <stdio.h>
int square[45][45];
int n,lastnum_r,lastnum_c;
bool is_lastc,is_firstr;
void print()
{
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=n;j++)
   printf("%d ",square[i][j]);
  puts("");
 }
 return;
}
void fill(int num)
{
 if(is_firstr&&(!is_lastc))
 {
  square[n][++lastnum_c]=num;
  if(lastnum_c==n)is_lastc=1;
  is_firstr=0;
  lastnum_r=n;
 }
 else if((!is_firstr)&&is_lastc)
 {
  square[--lastnum_r][1]=num;
  if(lastnum_r==1)is_firstr=1;
  is_lastc=0;
  lastnum_c=1;
 }
 else if(is_firstr&&is_lastc)
 {
  square[++lastnum_r][lastnum_c]=num;
  is_firstr=0;
 }
 else
 {
  if(!square[lastnum_r-1][lastnum_c+1])
  {
   square[--lastnum_r][++lastnum_c]=num;
   if(lastnum_c==n)is_lastc=1;
   if(lastnum_r==1)is_firstr=1;
  }
  else
  {
   square[++lastnum_r][lastnum_c]=num;
   is_firstr=0;
  }
 }
 return;
}
int main()
{
 scanf("%d",&n);
 square[1][(n+1)/2]=1;
 is_firstr=1;
 lastnum_r=1;
 lastnum_c=(n+1)/2;
 for(int i=2;i<=n*n;i++)
  fill(i);
 print();
 return 0;
}
