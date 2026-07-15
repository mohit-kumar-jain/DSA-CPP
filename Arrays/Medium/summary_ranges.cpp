#include<bits/stdc++.h>
using namespace std;
                   
vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        string first = to_string(nums[i]);
        int j = i;
        while (j < nums.size() - 1 && nums[j + 1] == nums[j] + 1)
        {
            j++;
        }
        if (j != i)
        {
            string second = to_string(nums[j]);
            ans.push_back(first + "->" + second);
        }
        else
        {
            ans.push_back(first);
        }
        i = j;
    }
    return ans;
}                  
                   
int main() {
    vector<int> nums = {0,1,2,4,5,6,9,10,15};
    vector<string> res = summaryRanges(nums);
    for(auto it : res) cout << it << endl;
    return 0;
}
