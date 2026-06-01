#include<bits/stdc++.h>
                   
using namespace std;
void hashing(int val,int arr[],int n){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (val == arr[i])
        {
                count = count+  1;
        }
        
    }
    cout<< count<<endl;
}                   
int main() {
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        int val;
        cin>>val;
        hashing(val,arr,n);

    }
    
    return 0;
}