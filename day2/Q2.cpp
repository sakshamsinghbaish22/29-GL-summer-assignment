#include<iostream>
using namespace std;
int main()
{
int i,rev;
cout<<" enter the number ";
cin>>i;
while(i>0)
{
rev=(rev*10)+i%10;
i=i/10;

}
cout<<"the reverse  "<<rev;



    return 0;

}