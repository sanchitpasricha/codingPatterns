#include<iostream>
#include<vector>

using namespace std;

vector<int> nextLargestNum(vector<int> nums){
    int n = nums.size();
    vector<int> res(n,0);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }

        res[i] = !st.empty() ? st.top() : -1;
        st.push(nums[i]);
    }
    return res;
}

int main(){
    vector<int> nums = {1,1,2,3,2,3,2,4};
    vector<int> res = nextLargestNum(nums);

    cout<<"[ ";
    for(auto x : res){
        cout<<x<<" ";
    }
    cout<<"]";

    return 0;
}