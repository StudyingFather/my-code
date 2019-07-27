#include <cstdio>
int main()
{
 int y;
 scanf("%d",&y);
 printf("%d\n",14-((y-1911)+y/4-477)%7);
 return 0;
}