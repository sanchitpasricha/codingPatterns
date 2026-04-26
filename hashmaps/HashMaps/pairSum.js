function pair_sum_unsorted(nums, target) {
  const hashmap = {}
  for (let i = 0; i < nums.length; i++) {
    const x = nums[i]

    // x+y = target, y = target-x;
    if (target - x in hashmap) {
      return [hashmap[target - x], i]
    }
    hashmap[x] = i
  }
  return []
}

const nums = [-1,3,4,2];
const ans = pair_sum_unsorted(nums,3);
console.log(ans)