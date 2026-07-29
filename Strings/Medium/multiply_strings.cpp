#include <bits/stdc++.h>
using namespace std;
string multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
        return "0";

    int n = num1.size(), m = num2.size();

    vector<int> res(n + m);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int sum = ((num1[i] - '0') * (num2[j] - '0')) + res[i + j + 1];

            res[i + j + 1] = (sum % 10);
            res[i + j] += (sum / 10);
        }
    }

    string ans = "";

    for (int i = 0; i < n + m; i++)
    {
        if (ans.empty() && res[i] == 0)
            continue;

        ans += char(res[i] + '0');
    }
    return ans;
}

int main() {
    string s = "121";
    string s2 = "12105";
    cout << multiply(s,s2) << endl;
    return 0;
}