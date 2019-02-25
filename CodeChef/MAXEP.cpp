#include <stdio.h>
int n,c;
void solve_sub_1()
{
 for(int i=1;i<=n;i++)
 {
  printf("1 %d\n",i);
  fflush(stdout);
  int op;
  scanf("%d",&op);
  if(op==1)
  {
   printf("3 %d\n",i);
   fflush(stdout);
   return;
  }
 }
}
void solve_sub_2()
{
 int l=1,r=n;
 while(l<r)
 {
  int mid=(l+r)>>1;
  printf("1 %d\n",mid);
  fflush(stdout);
  int op;
  scanf("%d",&op);
  if(op==1)
  {
   r=mid;
   puts("2");
   fflush(stdout);
  }
  else l=mid+1;
 }
 printf("3 %d\n",l);
 fflush(stdout);
 return;
}
void solve_sub_3()
{
 
}
int main()
{
 scanf("%d%d",&n,&c);
 if(n<=1000)solve_sub_1();//value 15 pts
 else if(c<=50)solve_sub_2();//value 25 pts
 else solve_sub_3();//value 60 pts
 return 0;
}
