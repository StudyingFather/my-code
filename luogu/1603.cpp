#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const char word[][25]={"zero","one","two","three","four","five","six","seven","eight","nine",
                       "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
                       "eighteen", "nineteen", "twenty","a","both","another","first","second","third"};
const int num[]={0,1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
char s[55];
int a[15],cnt;
int main()
{
 for(int i=1;i<=6;i++)
 {
  scanf("%s",s);
  for(int j=0;j<=26;j++)
   if(!strcmp(s,word[j]))
   {
    a[++cnt]=num[j];
    break;
   }
 }
 sort(a+1,a+cnt+1);
 int flag=0;
 for(int i=1;i<=cnt;i++)
  if(flag)
  {
   printf("%.2d",a[i]);
  }
  else
  {
   if(a[i])
   {
    printf("%d",a[i]);
    flag=1;
   }
  }
 if(!flag)puts("0");
 return 0;
}