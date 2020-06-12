#include "Catherine.h"
#include <iostream>
using namespace std;
int a,b,lastc,fir,movec;
bool known,sta;
vector<int> step;
void Init(int A,int B)
{
 a=A,b=B;
}
int Move(vector<int> y)
{
 if(a>=3)//subtask 1-4
 {
  int p=-1,q=-1;
  for(int i=0;i<3;i++)
   if(y[i])p==-1?p=i:q=i;
  if(p!=-1&&q==-1)return p;
  return (p==0&&q==2)?2:p;
 }
 else//subtask 5-7
 {
  int cnt=0;
  for(auto x:y)
   cnt+=x;
  if(cnt+sta>=3)//point with >=3 degrees
  {
   known=true;
   if(!sta)
   {
    sta=true;
    return lastc=(y[1]==1);
   }
   if(!y[lastc])return -1;
   y[lastc]++;
   return lastc=(y[1]==1);
  }
  else if(cnt==1-sta)//get into leaf point
  {
   known=true;
   if(!sta)
   {
    sta=true;
    return lastc=(y[1]==1);
   }
   return -1;
  }
  else//2 degree point
  {
   sta=true;
   if(known)//only one choice
    return lastc=(y[1]==1);
   else
   {
    if(step.size()==0)//first step
    {
     if(y[0]==2)//00
     {
      fir=1,step.push_back(0);
      return lastc=0;
     }
     else if(y[1]==2)//11
     {
      fir=2,step.push_back(1);
      return lastc=1;
     }
     else //01
     {
      fir=3,step.push_back(0);
      return lastc=0;
     }
    }
    else if(step.size()==1)//second step
    {
     if(fir==1)//00
     {
      step.push_back(1);
      return lastc=1;
     }
     else if(fir==2)//11
     {
      step.push_back(0);
      return lastc=0;
     }
     else//01
     {
      if(y[1])
      {
       step.push_back(1);
       return lastc=1;
      }
      else
      {
       step.push_back(0);
       return lastc=0;
      }
     }
    }
    else if(step.size()==2)//third step
    {
     if(fir==1||fir==2)//00 or 11
     {
      known=true;
      if(y[0])//right way
       return lastc=0;
      else//wrong way
       return -1;
     }
     else//01
     {
      if(step[1]==0)
      {
       step.push_back(1);
       return lastc=1;
      }
      else
      {
       known=true;
       if(y[1])//right way
        return lastc=1;
       else//wrong way
        return -1;
      }
     }
    }
    else//last step,01 only
    {
     known=true;
     if(y[0])//right way
      return lastc=0;
     else
      return -1;
    }
   }
  }
 }
}