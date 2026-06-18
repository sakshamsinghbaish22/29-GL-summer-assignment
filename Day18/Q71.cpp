#include <iostream>
using namespace std;
int main()
{
int n;
cout << "Enter number of elements: ";
cin >> n;
int arr[n];
cout << "Enter sorted elements: ";
for(int i = 0; i < n; i++)
{
cin >> arr[i];
}
int key;
cout << "Enter element to search: ";
cin >> key;
int low = 0, high = n - 1;
int found = 0;
while(low <= high)
{
int mid = (low + high) / 2;
if(arr[mid] == key)
{
cout << "Element found at position " << mid + 1;
found = 1;
break;
}
else if(arr[mid] < key)
{
low = mid + 1;
}
else
{
high = mid - 1;
}
}
if(found == 0)
{
cout << "Element not found";
}
return 0;
}