#include <cstdio>
int main()
{
 int maxa=0,ans=0;
 for(int p=12;p<=1000;p++)
 {
  int cnt=0;
  for(int i=1;3*i<=p;i++)
   for(int j=i;(p-i-j)>=j;j++)
   {
    int k=p-i-j;
    if(i*i+j*j==k*k)cnt++;
   }
  if(cnt>maxa)maxa=cnt,ans=p;
  //printf("%d %d\n",p,cnt);
 }
 printf("%d\n",ans);
 return 0;
}