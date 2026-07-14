#include<iostream>
#include<vector>

using namespace std;

vector<int> pairSum(vector<int> nums, int target){
    unordered_map<int,int> mp;
    vector<int> ans;

    for(int i=0;i<nums.size();i++){
        auto it = mp.find(nums[i]);
        if(it != mp.end()){
            ans.push_back(mp[nums[i]]);
            ans.push_back(i);
            break;
        }
        int key = target - nums[i];
        mp[key] = i;
    }
    return ans;
}

int main(){
    vector<int> nums = {-1, 3, 4, 2};
    vector<int> ans = pairSum(nums, 3);
    for(auto x : ans){
        cout<<x<<" ";
    }

    return 0;
}