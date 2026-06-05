#include <iostream>
#include <cmath>

using namespace std;
long long getLargestPrimeFactor(long long n) {
    long long maxPrime = -1;
    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }
 for (long long i = 3; i * i <= n; i += 2) {
 while (n % i == 0) {
maxPrime = i;
n /= i; 
}
}
if (n > 2) {
maxPrime = n;
}
return maxPrime;
}
int main() {
long long num;
cout << "write the number : ";
if (cin >> num && num > 1) {
long long result = getLargestPrimeFactor(num);
cout << "The largest prime factor of " << num << " is: " << result << endl;
} else {
cout << "Please enter a valid integer greater than 1." << endl;
}
return 0;
}
