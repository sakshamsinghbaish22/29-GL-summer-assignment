#include<iostream>
using namespace std;
int main(){
int i,j;
for (i=1;i<=5;i++)
{
     for (int j = 1; j <= i; j++) {
            cout << j;
}

 for (int j = i - 1; j >= 1; j--) {
            cout << j;
 }
 cout<<endl;
}


    return 0; 
}