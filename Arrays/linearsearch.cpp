#include<bits/stdc++.h>
using namespace std;

int linearSearch(int a[],int n,int val){
    for (int i = 0; i < n; i++)
    {
        if (a[i] == val)
        {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int value;
    cin>>value;
    cout<< linearSearch(arr,n,value)<<endl;
    return 0;
}