#include <stdio.h>
#include <algorithm>
using namespace std;
struct student
{
 int num;
 int score;
}a[5005];
int m,n,line;
int cmp(const student&a,const student&b)
{
 if(a.score>b.score)return 1;
 if(a.score<b.score)return 0;
 if(a.num<b.num)return 1;
 return 0;
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d%d",&a[i].num,&a[i].score);
 m*=1.5;
 sort(a+1,a+n+1,cmp);
 line=a[m].score;
 for(int i=m+1;;i++)
  if(a[i].score==line)m++;
  else break;
 printf("%d %d\n",line,m);
 for(int i=1;i<=m;i++)
  printf("%d %d\n",a[i].num,a[i].score);
 return 0;
}
