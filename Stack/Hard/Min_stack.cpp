#include<bits/stdc++.h>
using namespace std;
                 
// Brute. T.C -> O(1), S.C -> O(2N).
// class MinStack{
//     private:
//         stack<pair<int,int>> st;
//     public:
//         void push(int val) {
//             if(st.empty()){
//                 st.push({val,val});
//             }
//             int mini = min(getMin(),val);
//             st.push({val,mini});
//             cout << "Successfully Inserted : " << val << endl;
//         }
//         void pop(){
//             int ele = st.top().first;
//             st.pop();
//             cout << "Successfully Deleted : " << ele << endl;
//         }
//         int top() {
//             return st.top().first;
//         }
//         int getMin(){
//             return st.top().second;
//         }
// };                   

// Optimal. T.C -> O(1) , S.C -> O(N).
class MinStack{
    private:
        stack<int> st;
        int mini;
    public:
        void push(int val) {
            if(st.empty()){
                st.push(val);
                mini = val;
            }
            if(val > mini){
                st.push(val);
            }else{
                st.push(2*val - mini);
                mini = val;
            }

            cout << "Successfully Inserted : " << val << endl;
        }
        void pop(){
            if(st.empty()){
                cout << "Stack is Empty. Cannot dequeue!!" << endl;
            }
            int ele = st.top();
            st.pop();
            if(ele < mini) {
                mini = 2 * mini - ele;
            }
            cout << "Successfully Deleted : " << ele << endl;
        }
        int top() {
            if(st.empty()) return -1;
            int ele = st.top();
            if (mini < ele) return ele;
            return mini;
        }
        int getMin() {
            return mini;
        }
};                   
                   
int main() {
    MinStack s;
    s.push(5);
    s.push(8);
    cout << "The Minimum elemnet of the stack is : " << s.getMin() << endl;
    s.pop();
    s.push(10);
    s.push(89);
    s.pop();
    s.push(14);
    cout << "The Minimum elemnet of the stack is : " << s.getMin() << endl;
    cout <<"The Top most element of the stack is : "<< s.top() << endl;
    return 0;
}