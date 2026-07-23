#include <iostream>
#include <vector>
using namespace std;

class btwRanges {
public:
    vector<int> nums;
    vector<int> prefixSum;

    btwRanges(const vector<int>& numbers) : nums(numbers) {
    prefixSum.resize(nums.size());

    if (!nums.empty()) {
        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
            }
        }
    }

    // sum of elements between [left and right]
    // [3 -7 6 0 -2 5]
    // [3 -4 2 2  0 5] = sum
    // [2,2,0] = (left = 2, right = 4)
    int findSumRange(int left, int right) {
        if (left == 0)
            return prefixSum[right];

        return prefixSum[right] - prefixSum[left - 1];
    }
};

int main() {
    vector<int> nums = {3, -7, 6, 0, -2, 5};
    btwRanges bRanges(nums);
    int ans = bRanges.findSumRange(2,4);
    cout<<ans;

    return 0;
}