#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack> 
using namespace std;
int d[1005],u[1005];
int main()
{
 int n;
 while(cin>>n&&n)
 {
  while(cin>>d[1]&&d[1])
  {
   for(int i=2;i<=n;i++) 
	cin>>d[i];	
   stack<int> S;
   int o=1,k=1;
   while(o<=n)
   {
	if(!S.empty()&&d[o]==S.top())
	{
	 S.pop();
	 o++;
	}
	else if(d[o]!=k)
	{
	 S.push(k);
	 if(k++>n)break;
	}
	else
	{
	 o++;
	 k++;
	}
   }
   if(o>n)cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
  }
  cout<<endl;
 }
 return 0;
}
