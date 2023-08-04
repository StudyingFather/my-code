#include <cstdio>
#include <algorithm>
using namespace std;
char s[2005][2005];
int r[2005][2005],c[2005][2005];
int main()
{
 int h,w,ans=0;
 scanf("%d%d",&h,&w);
 for(int i=1;i<=h;i++)
  scanf("%s",s[i]+1);
 for(int i=1;i<=h;i++)
 {
  int cnt=0,l=1;
  for(int j=1;j<=w;j++)
   if(s[i][j]=='.')cnt++;
   else
   {
    for(int k=l;k<j;k++)
     r[i][k]=cnt;
    r[i][j]=0;
    cnt=0,l=j+1;
   }
  for(int j=l;j<=w;j++)
   r[i][j]=cnt;
 }
 for(int i=1;i<=w;i++)
 {
  int cnt=0,l=1;
  for(int j=1;j<=h;j++)
   if(s[j][i]=='.')cnt++;
   else
   {
    for(int k=l;k<j;k++)
     c[k][i]=cnt;
    c[j][i]=0;
    cnt=0,l=j+1;
   }
  for(int j=l;j<=w;j++)
   c[j][i]=cnt;
 }
 for(int i=1;i<=h;i++)
  for(int j=1;j<=w;j++)
   ans=max(ans,r[i][j]+c[i][j]);
 printf("%d\n",ans-1);
 return 0;
}