#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int res[105],t,b;
void print()
{
 for(int i=1;i<=b;i++)
  cout<<res[i];
 cout<<endl;
 char ch;
 cin>>ch;
 if(ch=='N')exit(0);
 else return;
}
void rev()
{
 reverse(res+1,res+b+1);
}
void neg()
{
 for(int i=1;i<=b;i++)
  res[i]^=1;
}
void change(int x,int y,int px,int py)
{
 if(x&&y)
 {
  if(px!=res[x]&&py!=res[y])neg();
  else if(px!=res[x]&&py==res[y])rev();
  else if(px==res[x]&&py!=res[y])rev(),neg();
 }
 else if(x)
 {
  if(px!=res[x])neg();
 }
 else if(y)
 {
  if(py!=res[y])neg();
 }
}
int main()
{
 cin>>t>>b;
 while(t--)
 {
  memset(res,0,sizeof(res));
  int l=1,r=b,x=0,y=0,px,py;
  for(int i=1;i<=150;i++)
   if(i%10==1&&i>10)
   {
    if(x)
    {
     cout<<x<<endl;
     cin>>px;
     //cerr<<"Query #"<<i<<": "<<x<<' '<<px<<endl;
    }
    else
    {
     cout<<1<<endl;
     cin>>px;
    }
   }
   else if(i%10==2&&i>10)
   {
    if(y)
    {
     cout<<y<<endl;
     cin>>py;
     //cerr<<"Query #"<<i<<": "<<y<<' '<<py<<endl;
    }
    else
    {
     cout<<1<<endl;
     cin>>py;
    }
    change(x,y,px,py);
   }
   else
   {
    if(i&1)
    {
     cout<<l<<endl;
     cin>>res[l];
     //cerr<<"Query #"<<i<<": "<<l<<' '<<res[l]<<endl;
    }
    else
    {
     cout<<r<<endl;
     cin>>res[r];
     //cerr<<"Query #"<<i<<": "<<r<<' '<<res[r]<<endl;
     if(res[l]!=res[r])x=l;
     else y=l;
     l++,r--;
    }
    if(l>r)
    {
     print();
     break;
    }
   }
 }
 return 0;
}