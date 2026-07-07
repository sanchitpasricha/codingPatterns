#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pairSum(vector<int> nums, int start, int target);

vector<vector<int>> tripletSum(vector<int> nums){
    vector<vector<int>> triplets;
    vector<int> pairs;

    sort(nums.begin(),nums.end());
    
    for(int i=0;i<nums.size();i++){
        if(nums[i] > 0) break;

        if(i > 0 && nums[i] == nums[i-1]) continue;

        pairs = pairSum(nums, i+1, -nums[i]);

        for(int j = 0; j < pairs.size(); j += 2){
            triplets.push_back({nums[i], pairs[j], pairs[j + 1]});
        }
    }
    return triplets;
}

vector<int> pairSum(vector<int> nums, int start, int target){
    vector<int> pairs;
    int left = start;
    int right = nums.size()-1;

    while(left < right){
        int sum = nums[left] + nums[right];
        if(sum == target){
            pairs.push_back(nums[left]);
            pairs.push_back(nums[right]);
            left++;
            right--;

            while(left < right && nums[left] == nums[left - 1]){
                left++;
            }

            while(left < right && nums[right] == nums[right + 1]){
                right--;
            }
        }

        else if(sum < target){
            left += 1;
        }
        else{
            right -= 1;
        }
    }
    return pairs;

}

int main(){
    vector<int> nums = {-1,2,-2,1,-1,2};
    vector<vector<int>> triplets = tripletSum(nums);

    for(vector<int> triplet : triplets){
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << '\n';
    }

    return 0;
}
