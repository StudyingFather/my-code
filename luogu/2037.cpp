#include <stdio.h>
#include <string.h>
char s[1005];
const int ctoi[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
int used[10000005];
void calc()
{
 int num=0,l=strlen(s);
 for(int i=0;i<l;i++)
  if(s[i]=='-')continue;
  else if(s[i]>='0'&&s[i]<='9')num=num*10+s[i]-'0';
  else num=num*10+ctoi[s[i]-'A'];
 used[num]++;
 return;
}
int main()
{
 int n,flag=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  memset(s,0,sizeof(s));
  scanf("%s",s);
  calc();
 }
 for(int i=0;i<=9999999;i++)
  if(used[i]>=2)
  {
   int num_4=i%10000,num_3=i/10000;
   printf("%03d-%04d %d\n",num_3,num_4,used[i]);
   flag=1;
  }
 if(!flag)puts("No duplicates.");
 return 0;
}
