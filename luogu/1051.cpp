#include <cstdio>
#include <algorithm>
using namespace std;
struct student
{
 int qimo_score,banji_score,lunwen,shunxu,money;
 char ganbu,xibu,name[25];
}a[105];
int bijiao(const student&a,const student&b)
{
 if(a.money>b.money)return 1;
 if(a.money<b.money)return 0;
 if(a.shunxu<b.shunxu)return 1;
 return 0;
}
int total,n;
int jisuan(student&a)
{
 int money=0;
 if(a.qimo_score>80&&a.lunwen)money+=8000;
 if(a.qimo_score>85&&a.banji_score>80)money+=4000;
 if(a.qimo_score>90)money+=2000;
 if(a.qimo_score>85&&a.xibu=='Y')money+=1000;
 if(a.banji_score>80&&a.ganbu=='Y')money+=850;
 return money;
}
int main()
{
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
  scanf("%s %d %d %c %c %d",a[i].name,&a[i].qimo_score,&a[i].banji_score,&a[i].ganbu,&a[i].xibu,&a[i].lunwen);
  a[i].shunxu=i;
  a[i].money=jisuan(a[i]);
 }
 sort(a+0,a+n,bijiao);
 for(int i=0;i<n;i++)
  total+=a[i].money;
 printf("%s\n",a[0].name);
 printf("%d\n%d",a[0].money,total);
 return 0;
}
