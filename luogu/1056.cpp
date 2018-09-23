#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int a,num;
}row[1005],col[1005];
int cmp(const node&a,const node&b)
{
 return a.a>b.a;
}
int cmp2(const node&a,const node&b)
{
 return a.num<b.num;
}
int main()
{
 int m,n,k,l,d,x1,y1,x2,y2;
 scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
 for(int i=1;i<=1000;i++)
  row[i].num=i;
 for(int i=1;i<=1000;i++)
  col[i].num=i;
 for(int i=1;i<=d;i++)
 {
  scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
  if(x1==x2)col[min(y1,y2)].a++;
  else row[min(x1,x2)].a++;
 }
 sort(col+1,col+1000,cmp);
 sort(row+1,row+1000,cmp);
 sort(col+1,col+l+1,cmp2);
 sort(row+1,row+k+1,cmp2);
 for(int i=1;i<=k;i++)
  printf("%d ",row[i].num);
 printf("\n");
 for(int i=1;i<=l;i++)
  printf("%d ",col[i].num);
 return 0;
}
