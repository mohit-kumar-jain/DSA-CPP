#include<bits/stdc++.h>
                   
using namespace std;
                   
int main() {
    int n;
    cin>>n;
    int arr[n];
    //we can use map also but unordered map has T.C of O(1) for best and average cases.
    unordered_map<int ,int >mpp;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        mpp[arr[i]]+= 1;
    }
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)
    {
        int num;
        cin>>num;
        cout<<mpp[num]<<endl;
    }
    
    return 0;
}