#include <iostream>
#include <cstring>
using namespace std;
int a[2005],b[2005],c[4005];
char s1[2005],s2[2005],s3[4005];
int main()
{
 cin>>s1;
 cin>>s2; 
 int la,lb,len;
 la=strlen(s1);
 lb=strlen(s2);
 for(int i=1;i<=la;i++)
  a[i]=s1[la-i]-48;
 for(int i=1;i<=lb;i++)
  b[i]=s2[lb-i]-48;
 for(int i=1;i<=la;i++)
 for(int j=1;j<=lb;j++)
 {
  c[i+j-1]=c[i+j-1]+a[i]*b[j];
  c[i+j]=c[i+j]+c[j+i-1]/10;
  c[i+j-1]=c[i+j-1]%10;
 }
 len=la+lb;
 while(c[len]==0&&len>1) 
  len--;
 for(int i=len;i>=1;i--)
  cout<<c[i];
 return 0;
}
