#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const char s[][15]={"","XXXS","XXS","XS","S","M","L","XL","XXL","XXXL"};
char s1[15];
int a[105],b[105];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%s",s1);
  for(int j=1;j<=9;j++)
   if(strcmp(s1,s[j])==0)
   {
    a[j]++;
    break;
   }
 }
 for(int i=1;i<=n;i++)
 {
  scanf("%s",s1);
  for(int j=1;j<=9;j++)
   if(strcmp(s1,s[j])==0)
   {
    b[j]++;
    break;
   }
 }
 int ans=0;
 for(int i=1;i<=9;i++)
  ans+=abs(a[i]-b[i]);
 printf("%d",ans/2);
 return 0;
}
