#include <iostream>
using namespace std;

bool isPalindrome(int n)
{
    int rev = 0, temp = n;

    while(temp > 0)
    {
        int digit = temp % 10;
        rev = rev * 10 + digit;
        temp = temp / 10;
    }

    return (rev == n);
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if(isPalindrome(num))
        cout << "Palindrome Number";
    else
        cout << "Not a Palindrome Number";

    return 0;
}