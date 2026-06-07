#include<iostream>
using namespace std;
int fabonacci (int n)
{ 
    if (n==0)return 0;
    
    if (n==1) return 1;
    
    return fabonacci(n - 1) + fabonacci(n - 2);

}
int main(){


    int n,i;
    cout<<" enter the number "<<endl;
    cin>>n;
    cout<<" the febonacci series is ";
    for (i=0; i<=n; i++){
        cout<<fabonacci(i)<<" ";

    }
    return 0;

}