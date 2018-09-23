#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int ctoi[135];
int main()
{
 ctoi['^']=0;
 ctoi['>']=1;
 ctoi['v']=2;
 ctoi['<']=3;
 char a,b;
 int n,c,d,flag=0;
 scanf("%c %c",&a,&b);
 c=ctoi[a];
 d=ctoi[b];
 scanf("%d",&n);
 if((c+n)%4==d)flag++;
 if((c-n>=0?c-n:(int)(c-n+ceil((n-c)*1.0/4)*4))%4==d)flag+=2;
 if(flag==1)printf("cw");
 else if(flag==2)printf("ccw");
 else printf("undefined");
 return 0;
}
