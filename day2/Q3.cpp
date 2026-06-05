#include<iostream>
using namespace std;
int main(){
    int i, prod=1  ;
    cout<<" enter the number ";
    cin>>i;
while (i>0)
{
prod=prod* (i % 10) ;
i=i/10;
}
cout<<"/n the sum of digits is : "<<prod;
  


    return 0; 
}