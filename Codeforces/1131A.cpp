#include <iostream>
using namespace std;
long long w1,h1,w2,h2;
int main()
{
 cin>>w1>>h1>>w2>>h2;
 cout<<(h1+h2+2)*(w1+2)-(w1-w2)*h2-w1*h1-w2*h2<<endl;
 return 0;
}