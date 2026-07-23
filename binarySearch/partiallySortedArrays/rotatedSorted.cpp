#include<iostream>
#include<vector>

using namespace std;

int findNumber(vector<int> nums, int target){
    int left = 0;
    int right = nums.size()-1;

    // nums = 3 4 5 6 7 1 2

    while(left < right){
        int mid = left + (right - left) / 2;

        if(nums[mid] == target){
            return mid;
        }
        else if(nums[left] <= nums[mid]){
            // 3 4 5 6
            if(target > nums[left] && target < nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if(nums[mid] < target && target <= nums[right]){
                left = mid + 1;
            }            
            else{
                right = mid - 1;
            }
        }
    }

    return nums[left] == target ? left : -1;
}

int main(){
    vector<int> nums = {3,4,5,6,7,1,2};
    int index = findNumber(nums, 1);
    cout<<index;

    return 0;
}