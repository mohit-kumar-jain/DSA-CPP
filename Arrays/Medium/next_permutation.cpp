#include<bits/stdc++.h>
using namespace std;

// Optimal. T.C -> O(3n) ,S.C -> O(n/1).

void nextPermutation(vector<int>& nums,int n){
    int index = -1;
    for (int i = n-2; i >= 0; i--)
    {
        if(nums[i] < nums[i+1]){
            index = i;
            break;
        }
    }
    if(index == -1){
        reverse(nums.begin(),nums.end());
    }
    for (int i = n-1; i > index; i--)
    {
        if(nums[i] > nums[index]){
            swap(nums[i],nums[index]);
            break;
        }
    }
    reverse(nums.begin()+index+1,nums.end());
    for(auto it:nums){
        cout<<it<<" ";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++)
        cin >> arr[i]; 
    nextPermutation(arr,n);
    return 0;
}