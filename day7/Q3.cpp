#include<iostream>
 using namespace std;
 int sumDigit(int n){
    if (n==0) return 0;
    return (n%10)+sumDigit(n/10);
 }
 int main()
 {
    int n;
    cout<<" the number is ";
    cin>>n;
    cout<<" the sum of the digits is = "<<sumDigit(n);
    return 0;

 }