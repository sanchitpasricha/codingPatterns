#include <iostream>
#include <vector>

using namespace std;

vector<int> pairSum(vector<int> nums, int target){
    int start = 0;
    int end = nums.size() - 1;
    vector<int> ans;
    
    while(start < end){
        int sum = nums[start] + nums[end];

        if(sum < target){
            start++;
        }
        else if(sum > target){
            end--;
        }
        else{
            ans.push_back(start);
            ans.push_back(end);
            break;
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {-5,-2,3,4,6};
    int target = 7;
    vector<int> ans = pairSum(nums, target);
    for(auto x : ans){
        cout<<x<<" ";
    }
}