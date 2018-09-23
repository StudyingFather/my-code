#include<cmath>
#include<iostream>
using namespace std;
char c;
int a[10000][2],b=0,d=0,i,l=0,p=0,w=0;
int main()
{
 while(1)
 {
  cin>>c;
  if(c=='E')break;
  if(c=='W')
  {
   w++;
   b++;
  }
  else
  {
   l++;
   d++;
  }
  if((w>=11||l>=11)&&abs(w-l)>=2)
  {
   cout<<w<<':'<<l<<endl;
   w=0;
   l=0;
  }
  if((b>=21||d>=21)&&abs(b-d)>=2)
  {
   a[++p][0]=b;
   a[p][1]=d;
   b=0;
   d=0;
  }
 }
 cout<<w<<':'<<l<<"\n\n";
 for(i=1;i<=p;i++)
  cout<<a[i][0]<<':'<<a[i][1]<<endl;
 cout<<b<<':'<<d;
 return 0;
}
