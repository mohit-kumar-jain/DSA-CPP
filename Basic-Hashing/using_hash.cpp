#include<bits/stdc++.h>
                   
using namespace std;
                   
int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // pre computing
    int hash[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }


    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int n;
        cin>>n;

        // fetching

        cout << hash[n] << endl;   
             
    }
    return 0;
}