#include <stdio.h>
const char s[][20]={"move_left","move_right","reverse","reach_dest","dist"};
int is_rev,mind,cnt;
int main()
{
 int n,m,l,d;
 scanf("%d%d%d%d",&n,&m,&l,&d);
 while(1)
 {
  int flag;
  puts(s[3]);
  fflush(stdout);
  scanf("%d",&flag);
  puts(s[0]);
  fflush(stdout);
  scanf("%d",&flag);
 }
 return 0;
}