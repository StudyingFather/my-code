#include <cstdio>
#include <algorithm>
using namespace std;
int game(int x,int y)
{
 if(!y)return 0;
 else if(x/y==1)return !game(y,x%y);
 else return 1;
}
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  if(x<y)swap(x,y);
  if(game(x,y))puts("Stan wins");
  else puts("Ollie wins");
 }
 return 0;
}