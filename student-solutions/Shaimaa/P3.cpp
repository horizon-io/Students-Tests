
#include <iostream>
#include <string>
#include<cmath>

using namespace std;
int main()
{
  int net[4],sub[4],broad[4],nett[4];
  cout<<"IP address: (use space instead of'.') -> ";
  for(int i=0;i<4;i++)
  cin>>net[i];
  cout<<endl;
  cout<<"Subnet: (use space instead of'.') -> ";
  for(int i=0;i<4;i++)
  cin>>sub[i];
  cout<<endl;
  cout<<"network: "<<endl;
  for(int i=0;i<4;i++){
  nett[i]=net[i];
  nett[3]=0;

  cout<<nett[i];
  if(i>=0 && i<3)
  {
      cout<<".";
  }
  }
  cout<<endl;
  cout<<"broadcast: "<<endl;
    for(int i=0;i<4;i++){
           broad[i]=sub[i];
            if(sub[i]==0)
            broad[i]=255;
     if(sub[i]<255 && sub[i]!=0)
        broad[i]=sub[i]-1;


    cout<<broad[i];
    if(i>=0 && i<3)
    {
        cout<<".";
    }
  }
  return 0;
}

