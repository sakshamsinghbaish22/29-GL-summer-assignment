#include<iostream>
using namespace std;
int main(){
int i,x,rev=0;
cout<<"  enter the number ";
cin>>i;
while(i>0)
{
    rev=(rev*10)+i%10;
    i = i%10;

}

if (rev==x){
    cout<<"the number is palindrome";

}
else{
cout<<" the number is not a palindrome";
}




    return 0; 
}