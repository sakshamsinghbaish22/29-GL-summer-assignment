#include<iostream>
using namespace std;
int main()
{
int n;
cout<<" the number of the series";
cin>>n;
if (n<=0){
    cout<<" the febonachi series is not possible "<<endl;
}
if (n==1){
    cout<<" the febonachi series is :1"<<endl;
}
int i;
int x=0;
int y=1;
int z=0;
for (i=2; i<=n; i++){
    z=x+y;
    x=y;
    y=z;

}
cout<<" the"<<n<< "febonachi series is: " << y <<endl;


return 0;
 
}