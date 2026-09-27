#include<bits/stdc++.h>
using namespace std;
                   
// T.C -> O(N) , S.C -> O(1).
bool canJump(vector<int>& nums) {
    int maxIndex = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(i > maxIndex) return false;
        maxIndex = max(maxIndex, i + nums[i]);
    }
    return true;
}                   
                   
int main() {
    vector<int> nums = {3, 2, 3, 0, 4};
    canJump(nums)? cout <<"True" << endl : cout << "False" << endl;
    return 0;
}