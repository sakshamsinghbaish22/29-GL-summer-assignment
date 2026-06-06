#include<iostream>
using namespace std;
int main()
{
int i,x,y,ans=1;
cout<<" Enter the value of the x";
cin>>x;
cout<<" enter the value of y";
cin>>y;
for (i=1;i<=y;i++){

    ans*=x;

}
cout<<" "<<x<<"is the power of "<<y<<" ="<<ans;


    return 0;
}