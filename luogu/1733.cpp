// Problem : P1733 猜数（IO 交互版）
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P1733
// Memory Limit : 128 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int main()
{
 int l=1,r=1e9;
 while(1)
 {
  int mid=(l+r)>>1,res;
  cout<<mid<<endl;
  cin>>res;
  if(res==1)r=mid-1;
  else if(res==-1)l=mid+1;
  else return 0;
 }
 return 0;
}