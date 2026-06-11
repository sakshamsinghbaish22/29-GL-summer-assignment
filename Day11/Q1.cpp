#include<iostream>
using namespace std ;
int sum(int a,int b){
return a+b;
}
int main()
{
int a,b,c;
cout<<" the first number is ";
cin>>a;
cout<<" the second number ";
cin>>b;
cout<<" the sum of the two number is "<<sum(a,b);
return 0; 
}
