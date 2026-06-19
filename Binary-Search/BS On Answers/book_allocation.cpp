#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(N) + O((sum-max+1)), S.C -> O(1).

// bool isPossible(vector<int>& books, int papers, int students){
//     int n = books.size();
//     int student = 1,paperCnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if(books[i] + paperCnt > papers){
//             student++;
//             paperCnt = books[i];
//         }else{
//             paperCnt += books[i];
//         }   
//     }
//     return student <= students;
// }

// int allocation(vector<int>& books, int students){
//     int n = books.size();
//     if(students > n) return -1;
//     int minStudents = *max_element(books.begin(),books.end());
//     int maxStudents = accumulate(books.begin(),books.end(),0);
//     for (int i = minStudents; i < maxStudents; i++)
//     {
//         if(isPossible(books,i,students)){
//             return i;
//         }
//     }
//     return -1;
// }
// Optimal. T.C -> O(nlogn) + O(log(max-min) * n), S.C -> O(1).

// Optimal. T.C -> O(N) + O(log(sum-max+1)), S.C -> O(1).
bool isPossible(vector<int>& books, int papers, int students){
    int paperCnt = 0,student = 1;
    for (int i = 0; i < books.size(); i++)
    {
        if(books[i] + paperCnt <= papers){
            paperCnt += books[i];
        }else{
            student++;
            paperCnt = books[i];
        }
        
    }
    return (student <= students);
}
int allocation(vector<int>& books, int students){
    if(books.size() < students) return -1;
    int low = *max_element(books.begin(),books.end());
    int high = accumulate(books.begin(),books.end(),0);
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(isPossible(books,mid,students)){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}



int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int m = 4;
    cout << allocation(arr,m);
    return 0;
}