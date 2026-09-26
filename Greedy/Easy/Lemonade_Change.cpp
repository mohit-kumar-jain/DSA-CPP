#include<bits/stdc++.h>
using namespace std;
  
// T.C -> O(N) , S.C -> O(1).
bool lemonadeChange(vector<int>& bills) {
    int fives = 0, tens = 0;
    for (int i = 0; i < bills.size(); i++)
    {
        if(bills[i] == 5) {
            fives += 1;
        }else if(bills[i] == 10) {
            if(fives){
                fives -= 1;
                tens += 1;
            }else{
                return false;
            }
        }else {
            if(fives && tens) {
                fives -= 1;
                tens -= 1;
            }else if(fives >= 3){
                fives -= 3;
            }else {
                return false;
            }
        }
    }
    return true;
}                   
                   
int main() {
    vector<int> bills = {5, 5, 10, 10, 20};
    lemonadeChange(bills)? cout<< "True" << endl: cout << "False" << endl;
    return 0;
}