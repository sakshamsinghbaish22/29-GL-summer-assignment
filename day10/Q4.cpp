#include<iostream>
using namespace std;
int main()
{

int i,j;
  for (int i = 0; i < 5; i++) 
  {
     for (int j = 0; j <= i; j++) 
     {
            cout << char('A' + j);
        }



           for (int j = i - 1; j >= 0; j--) 
           {
            cout << char('A' + j);
        }


        cout<<endl;


  }





    return 0; 
}