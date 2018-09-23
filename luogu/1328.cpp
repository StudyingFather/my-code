#include <stdio.h>
const int result[5][5]={{0,-1,1,1,-1},{1,0,-1,1,-1},{-1,1,0,-1,1},{-1,-1,1,0,1},{1,1,-1,-1,0}};
int n,na,nb,a[205],b[205];
int main()
{
 scanf("%d%d%d",&n,&na,&nb);
 for(int i=0;i<na;i++)
  scanf("%d",&a[i]);
 for(int i=0;i<nb;i++)
  scanf("%d",&b[i]);
 int sa=0,sb=0;
 for(int i=0;i<n;i++)
  if(result[a[i%na]][b[i%nb]]==1)sa++;
  else if(result[a[i%na]][b[i%nb]]==-1)sb++;
 printf("%d %d",sa,sb);
 return 0;
}
