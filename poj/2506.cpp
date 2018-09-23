#include<cstdio>
#include<cstring>
#include<cstdlib>
char C[260][1000],a[1000],b[1000];
void mult(char c[],char t[],int m)
{
 int i,l,k,flag,add=0;
 char s[100];
 l=strlen(c);
 for(i=0;i<l;i++)
  s[l-i-1]=c[i]-'0';
 for(i=0;i<l;i++)
 {
  k=s[i]*m+add;
  if(k>=10) 
  {
   s[i]=k%10;
   add=k/10;
   flag=1;
  } 
  else 
  {
   s[i]=k;
   flag=0;
   add=0;
  }
 }
 if(flag) 
 {
  l=i+1;
  s[i]=add;
 } 
 else l=i;
 for(i=0;i<l;i++)
  t[l-1-i]=s[i]+'0';
 t[l]='\0';
}
void add(char a[],char b[],char back[])
{
 int i,j,k,up,x,y,z,l;
 char *c;
 if(strlen(a)>strlen(b))l=strlen(a)+2; 
 else l=strlen(b)+2;
 c=(char *)malloc(l*sizeof(char));
 i=strlen(a)-1;
 j=strlen(b)-1;
 k=0;
 up=0;
 while(i>=0||j>=0)
 {
  if(i<0)x='0'; 
  else x=a[i];
  if(j<0)y='0'; 
  else y=b[j];
  z=x-'0'+y-'0';
  if(up)z+=1;
  if(z>9) 
  {
   up=1;
   z%=10;
  } 
  else up=0;
  c[k++]=z+'0';
  i--;
  j--;
 }
 if(up)c[k++]='1';
 i=0;
 c[k]='\0';
 for(k-=1;k>=0;k--)
  back[i++]=c[k];
 back[i]='\0';
}
int main()
{
 int i=0;
 C[1][0]='1';
 C[1][1]='\0';
 C[2][0]='3';
 C[2][1]='\0';
 for(i=3;i<=250;i++)
 {
  mult(C[i-2],a,2);
  add(C[i-1],a,C[i]);
 }
 while(scanf("%d",&i)!=EOF)
 {
  if(i==0)printf("1\n");
  else printf("%s\n",C[i]);
 }
 return 0;
}
