#include <cstdio>
#include <algorithm>
using namespace std;
int n;
struct student
{
 int num,ch_score,ma_score,en_score,total_score;
}a[305];
int cmp(const student&a,const student&b)
{
 if(a.total_score>b.total_score)return 1;
 if(a.total_score<b.total_score)return 0;
 if(a.ch_score>b.ch_score)return 1;
 if(a.ch_score<b.ch_score)return 0;
 if(a.num<b.num)return 1;
 return 0;
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d%d",&a[i].ch_score,&a[i].ma_score,&a[i].en_score);
  a[i].num=i;
  a[i].total_score=a[i].ch_score+a[i].ma_score+a[i].en_score;
 }
 sort(a+1,a+n+1,cmp);
 for(int i=1;i<=5;i++)
  printf("%d %d\n",a[i].num,a[i].total_score);
 return 0;
}
