#include<bits/stdc++.h>
using namespace std;
// Optimal Method.Time Complexity -> O(n), Space Complexity -> O(1).
void leftRotate(int arr[], int n)
{
    int temp = arr[0];
    for(int i = 1; i < n; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp; 
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    cout<<endl;
} 

void rightRotate(int arr[], int n)
{
    int temp = arr[n - 1];
    for(int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // rightRotate(arr,n);
    leftRotate(arr,n);
    return 0;
}