#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s1[10005],s2[10005];
int a[10005],b[10005],c[10005];
int main()
{
 scanf("%s%s",s1,s2);
 if(strlen(s1)<strlen(s2)||(strlen(s1)==strlen(s2)&&strcmp(s1,s2)<0))
 {
  printf("-");
  swap(s1,s2);
 }
 int n=strlen(s1),m=strlen(s2);
 for(int i=0;i<n;i++)
  a[n-i]=s1[i]-'0';
 for(int i=0;i<m;i++)
  b[m-i]=s2[i]-'0'; 
 for(int i=1;i<=n;i++)
  c[i]=a[i]-b[i]; 
 for(int i=1;i<=n;i++)
  if(c[i]<0)
  {
   c[i]+=10;
   c[i+1]-=1;
  }
 while((!c[n])&&n>0)
  n--;
 for(int i=n;i>=1;i--)
  printf("%d",c[i]);
 if(n==0)puts("0");
 return 0;
}
