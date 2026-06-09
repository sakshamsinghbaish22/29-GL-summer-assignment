#include<iostream>
using namespace std;
int main()
{
int i,j;
for(i=1;i<=5;i++)
{   char ch='A'+i-1;
    for (int j = 1; j <= i; j++){

        cout<<ch;

    }cout<<endl;
    
}



return 0;
}