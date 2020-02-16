#include <cstdio>
int ans[505][505];
int main()
{
 int k;
 scanf("%d",&k);
 if(k==1)
 {
  puts("1");
  puts("1");
  return 0;
 }
 int n=(k+1)/2;
 if(n%2)n++;
 printf("%d\n",n);
 for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
   ans[i][j]=n*(i%2)+(i+j)%n+1;
 for(int c=2*n;c>k;c--)
  for(int i=1;i<n;i+=2)
   for(int j=0;j<n;j++)
    if(ans[i][j]==c)ans[i][j]-=n;
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
   printf("%d ",ans[i][j]);
  puts("");
 }
 return 0;
}
