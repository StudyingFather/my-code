#include <stdio.h>
#include <string.h>
int light[15][15],anniu[15][15],moni[15][15];
void an(int r,int c)
{
 anniu[r][c]=1;
 moni[r][c]=!moni[r][c];
 if(r!=1)moni[r-1][c]=!moni[r-1][c];
 if(r!=5)moni[r+1][c]=!moni[r+1][c];
 if(c!=1)moni[r][c-1]=!moni[r][c-1];
 if(c!=6)moni[r][c+1]=!moni[r][c+1];
 return;
}
void solve(int num)
{
 for(int i=0;i<=1;i++)
  for(int j=0;j<=1;j++)
   for(int k=0;k<=1;k++)
    for(int l=0;l<=1;l++)
     for(int m=0;m<=1;m++)
      for(int n=0;n<=1;n++)
      {
       int flag=1;
	   memcpy(moni,light,sizeof(light));
       memset(anniu,0,sizeof(anniu));
       if(i)an(1,1);
       if(j)an(1,2);
       if(k)an(1,3);
       if(l)an(1,4);
       if(m)an(1,5);
       if(n)an(1,6);
       for(int r=1;r<=4;r++)
        for(int c=1;c<=6;c++)
         if(moni[r][c])an(r+1,c);
       for(int r=1;r<=5;r++)
        for(int c=1;c<=6;c++)
         if(moni[r][c])flag=0;
       if(flag)
       {
       	printf("PUZZLE #%d\n",num);
		for(int r=1;r<=5;r++)
        {
         for(int c=1;c<=6;c++)
          if(c==1)printf("%d",anniu[r][c]);
          else printf(" %d",anniu[r][c]);
         puts("");
        }
        return;
       }
      }
}
int main()
{
 int t;
 scanf("%d",&t);
 for(int i=1;i<=t;i++)
 {
  for(int r=1;r<=5;r++)
   for(int c=1;c<=6;c++)
    scanf("%d",&light[r][c]);
  solve(i);
 }
 return 0;
}
