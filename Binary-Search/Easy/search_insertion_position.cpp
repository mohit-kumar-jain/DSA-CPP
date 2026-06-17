#include <bits/stdc++.h>
using namespace std;

//Similar to lower_bound method. 
int searchPosition(vector<int>& nums,int target){
    int n = nums.size();
    int low = 0,high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] >= target){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 4, 7, 9, 13, 15};
    int n = arr.size();
    int target;
    cin >> target;
    cout << searchPosition(arr, target);
    return 0;
}