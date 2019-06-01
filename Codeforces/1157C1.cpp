#include <cstdio>
#include <algorithm>
using namespace std;
char s[200005];
int a[200005],cnt;
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 int cur=0,l=1,r=n;
 while(l<=r)
  if(a[l]<a[r])
  {
   if(a[l]>cur)
   {
    s[++cnt]='L';
    cur=a[l++];
   }
   else if(a[r]>cur)
   {
    s[++cnt]='R';
    cur=a[r--];
   }
   else break;
  }
  else
  {
   if(a[r]>cur)
   {
    s[++cnt]='R';
    cur=a[r--];
   }
   else if(a[l]>cur)
   {
    s[++cnt]='L';
    cur=a[l++];
   }
   else break;
  }
 printf("%d\n",cnt);
 puts(s+1);
 return 0;
}