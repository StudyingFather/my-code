#include <stdio.h>
#include <math.h>
#include <string.h>
int a[35];
char b[105];
int prime(int n)
{
 if(n==1||n==0)return 0;
 else for(int i=2;i<=sqrt(n);i++)
 {
  if(n%i==0&&n!=i)return 0;
 }
 return 1;
}
int main()
{
 int x,max=0,min=120,len;
 scanf("%s",b);
 len=strlen(b);
 for(int i=0;i<len;i++)
 {
  x=b[i]-96;
  a[x]++;
 }
 for(int i=1;i<=26;i++)
 {
  if(!a[i])continue;
  else if(a[i]>max)max=a[i];
  else if(a[i]<min)min=a[i];
 }
 int k=max-min;
 if(strlen(b)==1)k=1;
 int flag=prime(k);
 if(flag)
 {
  printf("Lucky Word\n");
  printf("%d",k);
 }
 else printf("No Answer\n0");
 return 0; 
}
