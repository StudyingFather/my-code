#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
int count[15],scan[5005][3];
int main()
{
 int s,s1,x,y,z,n=0;
 while(cin>>scan[n][0]>>scan[n][1]>>scan[n][2])
 {
  if(!scan[n][0]&&!scan[n][1]&&!scan[n][2])break;
  n++;
 }
 for(int i=0;i<n;i++)
 {
  s=5005;
  for(int j=0;j<n;j++)
  {
   if(j!=i)
   {
    x=scan[i][0]-scan[j][0];
    y=scan[i][1]-scan[j][1];
    z=scan[i][2]-scan[j][2];
    s1=(int)sqrt(x*x+y*y+z*z);
    if(s>s1)s=s1;
   }
  }
  if(s>=10)continue;
  count[s]++;
 }
 for(int i=0;i<10;i++)
  cout<<setw(4)<<count[i];
 cout<<endl;
 return 0;
}
