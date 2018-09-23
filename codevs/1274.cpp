#include <iostream>
using namespace std;
int main()
{
 int a,b,c;
 cout<<"Enter the speed limit: ";
 cout<<"Enter the recorded speed of the car: ";
 cin>>a>>b;
 if(b-a<=0)cout<<"Congratulations, you are within the speed limit";
 else
 {
  if(b-a<=20)c=100;
  else if(b-a<=30)c=270;
  else c=500;
  cout<<"You are speeding and your fine is $ "<<c;
 }
 return 0;
}
