#include <iostream>
using namespace std;
char a[105][105],b[105][105];
int m,n;
void work()
{
 for(int i=1;i<=m;i++)
  for(int j=1;j<=n;j++)
  {
   if(b[i][j]=='*')continue;
   if(b[i-1][j-1]=='*')b[i][j]++;
   if(b[i][j-1]=='*')b[i][j]++;
   if(b[i+1][j-1]=='*')b[i][j]++;
   if(b[i-1][j]=='*')b[i][j]++;
   if(b[i+1][j]=='*')b[i][j]++;
   if(b[i-1][j+1]=='*')b[i][j]++;
   if(b[i][j+1]=='*')b[i][j]++;
   if(b[i+1][j+1]=='*')b[i][j]++;
  }
}
void print()
{
 for(int i=1;i<=m;i++)
 {
  for(int j=1;j<=n;j++)
   if(c[i][j]=='*')cout<<'*'
   else cout<<b[i][j]+'0';
  cout<<endl;
 }
}
int main()
{
 //貌似用scanf会出问题 
 cin>>m>>n;
 for(int i=1;i<=m;i++)
  for(int j=1;j<=n;j++)
  {
   cin>>a[i][j];
   if(a[i][j]=='*')b[i][j]='*';
  }
 work();
 print();
 return 0;
}
