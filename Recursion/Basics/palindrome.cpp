#include <bits/stdc++.h>
using namespace std;

bool palin(string &s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (palin(s))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}