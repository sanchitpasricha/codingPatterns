#include<iostream>
#include<vector>

using namespace std;

int lowerBound(vector<int> nums, int target){
    int left = 0;
    int right = nums.size()-1;

    while(left < right){
        int mid = left + (right - left) / 2;
        if(nums[mid] > target){
            right = mid - 1;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return nums[left] == target  ? left : -1;
}

int upperBound(vector<int> nums, int target){
    int left = 0;
    int right = nums.size()-1;

    while(left < right){
        int mid = left + (right - left) / 2 + 1;
        if(nums[mid] > target){
            right = mid - 1;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            left = mid;
        }
    }
    return nums[right] == target  ? right : -1;
}

vector<int> findUpperLowerBound(vector<int> nums, int target){
    int lower = lowerBound(nums, target);
    int upper = upperBound(nums, target);

    vector<int> ans;
    ans.push_back(lower);
    ans.push_back(upper);

    return ans;
}

int main(){
    vector<int> nums = {1,2,3,4,4,4,5,6,7,8,9,10,11};
    vector<int> ans = findUpperLowerBound(nums, 4);
    cout<<"[ ";
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"]";
    return 0;

}