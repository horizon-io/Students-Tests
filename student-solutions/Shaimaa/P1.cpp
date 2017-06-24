
#include <iostream>
#include <string>
using namespace std;
 int n,i,j;
int main()
{   char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char b[n];
    bool check;
     try1: cout<<"length array=";
     cin>>n;
     if(n<2){
        cout<<"size of array must be greater than 2"<<endl;
        goto try1;
     }
     else{

for(i=0;i<n;i++)
  cin>>b[i];

 for(i=0; i<25; i++)
 {
     check=true;
     for(j=0; j<n; j++)
     {
         if(a[i]==b[j]){
            check=false;
            break;
         }
     }
     if(check)
     {
          cout<<"--> "<<a[i]<<endl;
          break;
     }
 }
}
return 0;
}

