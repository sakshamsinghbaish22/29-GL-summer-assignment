#include<iostream>
using namespace std;
int main()
{
int n;
int x=0,y=1,z=0,i=1;
cout<<" the series upto";
cin>>n;
while(i<n){
    if(i==1){
        cout<<x<<",";
        i++;
        continue;
    }
    if (i==2){
        cout<<y<<",";
        continue;
    }

    x=x+y;
    x=y;
    y=z;
    if(i==n){
        cout<<z;
    }
    else{
        cout<<z<<",";
    }
    i++;
}
cout<<endl;




return 0;
 
}