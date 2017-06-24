
#include <iostream>
#include <string>
#include<cmath>

using namespace std;
int bin(int n){
    int i=0,d=0,rem=0;
  while(n!=0)
   {
       rem=n%10;
       n /=10;
       d += rem * pow(2,i);
       ++i;
   }

   return d;
}


int main()
{
int b,c,d,e;
   cout<<"first binary=";
   cin>>c;
   d=bin(c);
   cout<<"second binary=";
   cin>>b;
   e=bin(b);
int z=d+e;
cout<<"result="<<z<<endl;

return 0;
}

