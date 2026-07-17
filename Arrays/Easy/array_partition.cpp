#include<bits/stdc++.h>
using namespace std;
                   
int arrayPartition(vector<int>& arr){
    sort(arr.begin(),arr.end());
    int sum = 0;
    for (int i = 0; i < arr.size(); i+=2)
    {
        sum += min(arr[i],arr[i+1]);
    }
    return sum;
}                   
                   
int main() {
    vector<int> nums = {1,5,2,3,8,6,8,2,5,9};
    cout << arrayPartition(nums) << endl;
    return 0;
}