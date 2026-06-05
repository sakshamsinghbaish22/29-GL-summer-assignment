#include <iostream>
#include <cmath>
using namespace std;

int main() {
int a,b;
cout<<" the value of first itiger";
cin>>a;
cout<<" the value of second intiger ";
cin>>b;


    a = abs(a);
    b = abs(b);

    if (a == 0 && b == 0) {
        cout << "Undefined";
        return 0;
    }

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    cout << a;
    return 0;
}