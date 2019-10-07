/*
 Name: CodeChef WATCHFB
 Author: StudyingFather
 Date: 2019/10/06 21:27
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
bool check(int a,int b,int x,int y)
{
 if(a>b)swap(a,b);
 if(x>y)swap(x,y);
 return a<y;
}
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int n,x=0,y=0;
  bool flag=false;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
   int op,a,b;
   scanf("%d%d%d",&op,&a,&b);
   if(op==1||a==b||(flag&&check(a,b,x,y)))
   {
    puts("YES");
    flag=true;
    if(op==1||a==b)x=a,y=b;
    else
    {
     if(a>x)x=a,y=b;
     else x=b,y=a;
    }
   }
   else
   {
    puts("NO");
    flag=false;
   }
  }
 }
 return 0;
}