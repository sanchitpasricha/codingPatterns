#include<iostream>
#include<vector>

using namespace std;

int insertionIndex(vector<int> nums, int target){
    int left = 0;
    int right = nums.size();

    while(left < right){
        int mid = left + (right - left) / 2;

        if(nums[mid] >= target){
            right = mid;
        }
        else{
            left = mid+1;
        }
    }

    return left;
}

int main(){
    vector<int> nums = {1,2,4,5,7,8,9};
    cout<<insertionIndex(nums,6)<<endl;
    cout<<insertionIndex(nums,4);

    return 0;
}