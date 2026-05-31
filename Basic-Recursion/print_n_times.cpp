#include<bits/stdc++.h>
                   
using namespace std;
void call(string name,int n){
    if (n==0){
        return;
    }
    cout<<name<<endl;
    call(name,n-1);
}                   
int main() {
    string name = "MOHIT JAIN";
    int n1;
    cin >> n1;
    call(name,n1);
    return 0;
}