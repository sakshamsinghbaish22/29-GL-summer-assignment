#include<iostream>
using namespace std;
int main()
{
    int i, sum=0  ;
    cout<<" enter the number ";
    cin>>i;
while (i>0)
{
sum=sum + (i % 10) ;
i=i/10;
}
cout<<"/n the sum of digits is : "<<sum;
  

return 0; 
}