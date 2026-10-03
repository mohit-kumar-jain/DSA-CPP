#include <bits/stdc++.h>
using namespace std;

void search(int start, int left, int target, vector<int> &current, vector<vector<int>> &answer)
{
    if (left == 0)
    {
        if (target == 0)
        {
            answer.push_back(current);
        }
        return;
    }
    if (target <= 0)
    {
        return;
    }
    for (int value = start; value <= 9; ++value)
    {
        if (value > target)
        {
            break;
        }
        current.push_back(value);
        search(value + 1, left - 1, target - value, current, answer);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> answer;
    vector<int> current;
    search(1, k, n, current, answer);
    return answer;
}

int main() {
    int k = 3 , n = 7;
    vector<vector<int>> res = combinationSum3(k,n);
    for(auto it : res) {
        for(auto row : it){
            cout << row << " ";
        }
        cout << endl;
    }
    return 0;
}