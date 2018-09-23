#include <stdio.h>
int a[10005];//模拟路的长度 
int main()
{
 int b=0,l,m;//l代表马路的长度，m代表区域的数目 
 scanf("%d %d",&l,&m);
 for(int i=0;i<=l;i++)
  a[i]=1;//开始路上都有树 
 for(int i=0;i<m;i++)
 {
  int a1,a2;//区域的左坐标，右坐标 
  scanf("%d %d",&a1,&a2);
  for(int j=a1;j<=a2;j++)
   a[j]=0;//将区域内树“铲除”，即置0 
 }
 for(int i=0;i<=l;i++)
  if(a[i])b++;//判断每个点有没有树 
 printf("%d",b);
 return 0;
}
