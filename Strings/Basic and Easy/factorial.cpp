#include <bits/stdc++.h>
using namespace std;

// Optimal. T.C. -> O(num*number of digits(input)), S.C. -> O(no,of,digits in factorial).
vector<int> factorial(int num)
{
    vector<int> res(1,1);
    while(num > 1){
        int sum,carry = 0,size = res.size();
        for (int i = 0; i < size; i++)
        {
            sum = res[i] * num + carry;
            res[i] = sum % 10;
            carry = sum / 10;
        }
        while(carry){
            res.push_back(carry % 10);
            carry /= 10;
        }
        num--;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    int num = 5;
    vector<int> res = factorial(num);
    for(auto it : res){
        cout << it << "";
    }
    return 0;
}