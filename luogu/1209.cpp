#include <cstdio>
#include <algorithm>
using namespace std;
int a[205],ans,gap[205];
int cmp(int a,int b)
{
 return a>b;
}
int main()
{
 int m,s,c;
 scanf("%d%d%d",&m,&s,&c);
 if(m>c)//如果木板数>牛数，直接输出 
 {
  printf("%d",c);
  return 0;
 }
 for(int i=1;i<=c;i++)
  scanf("%d",&a[i]);
 sort(a+1,a+c+1);
 ans=a[c]-a[1]+1; 
 for(int i=2;i<=c;i++)
  gap[i]=a[i]-a[i-1];
 sort(gap+2,gap+c+1,cmp);
 for(int i=2;i<=m;i++)
  ans-=gap[i]-1;//注意间隔数
 printf("%d",ans);
 return 0;
}
