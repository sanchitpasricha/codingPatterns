#include<iostream>
#include<vector>

using namespace std;

int countKSum(vector<int> nums, int k){
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;
    int count = 0;
    int curr_prefix_sum = 0;

    // 0 1 2 -1 1 2

    for(auto num : nums){
        curr_prefix_sum += num;
        if(prefixSum.find(curr_prefix_sum - k) != prefixSum.end()){
            count += prefixSum[curr_prefix_sum - k];
        }
        int freq = prefixSum[curr_prefix_sum];
        prefixSum[curr_prefix_sum] = freq + 1;
    }
    return count;
}

int main(){
    vector<int> nums = {1,2,-1,1,2};
    cout<<countKSum(nums, 3);

    return 0;
}