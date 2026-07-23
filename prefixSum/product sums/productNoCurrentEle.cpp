#include<iostream>
#include<vector>

using namespace std;

vector<int> productEle(vector<int> nums){
    int size = nums.size();
    vector<int> res(size,1);

    for(int i=1;i<size;i++){
        res[i] = res[i-1] * nums[i-1];
    }

    int rightProduct = 1;

    for(int i=size-1;i>=0;i--){
        res[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    return res;
}

int main(){
    vector<int> nums = {2,3,1,4,5};
    vector<int> ans = productEle(nums);

    cout<<"[ ";
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"]";

    return 0;
}