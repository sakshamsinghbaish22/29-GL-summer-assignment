#include<iostream>
using namespace std;
int main()
{
int n , i ;
long factorial = 1.0;
cout<<" write the number ";
cin>>n;
if (n<0){
    cout<<" the factorial is not possible ";
}

else{
    for (i=1; i<=n ;i++){
        factorial*=i;
}
}

    cout<<"factorial of"<<n<<" = "<<factorial;
    

return 0; 
}