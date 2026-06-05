#include<iostream>
using namespace std;
int main ()
{  
 int i, num, div, sum=0;
cout << "Enter the number to be checked : ";
 cin >> num;
for (i=1; i < num; i++)
{
div = num % i;
if (div == 0)
sum = sum + i;
}
if (sum == num)
cout << "\n" << num <<" perfect number.";
else
cout << "\n" << num <<"  not perfect number.";
return 0;
}