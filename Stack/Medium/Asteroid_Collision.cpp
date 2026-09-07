#include<bits/stdc++.h>
using namespace std;
                   
vector<int>  asteroidCollision(vector<int>& nums) {
    vector<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] > 0) st.push_back(nums[i]);
        else{
            while(!st.empty() && st.back() > 0 && st.back() < abs(nums[i])){
                st.pop_back();
            }
            if(!st.empty() && st.back() == abs(nums[i])){
                st.pop_back();
            } else if(st.empty() && st.back() < 0) {
                st.push_back(nums[i]);
            }
        }

    }
    return st;
}      
                   
int main() {
    vector<int> nums = {10,-10,30};
    vector<int> res = asteroidCollision(nums);
    for(int it : res) cout << it << " ";
    cout << endl;
    return 0;
}