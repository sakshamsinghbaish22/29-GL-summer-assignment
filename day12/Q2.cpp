#include <iostream>
using namespace std;

int armstrong(int n)
{
    int sum = 0, rem, temp = n;

    while(temp > 0)
    {
        rem = temp % 10;
        sum = sum + (rem * rem * rem);
        temp = temp / 10;
    }

    if(sum == n)
        return 1;
    else
        return 0;
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if(armstrong(num))
        cout << "Armstrong Number";
    else
        cout << "Not an Armstrong Number";

    return 0;
}