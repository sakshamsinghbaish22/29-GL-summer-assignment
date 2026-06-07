#include<iostream>
using namespace std;

int factorial (int n){
    if(n==0||n==1)
    return 1;
    return n * factorial (n-1);
} 
int main()
{
    int n ;
    cout<<"enter the number ";
    cin>>n;
    cout<<"factorial of  "<<n<< endl<<factorial(n);
    return 0;

}