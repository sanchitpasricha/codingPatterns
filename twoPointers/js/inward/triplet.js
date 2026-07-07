export function triplet_sum(nums) {
// b+c = -a, fix a and b+c == -(a) to make it zero

  const answer= [];
  nums.sort((a,b) => a - b);
  for(let i=0; i<nums.length; i++){
    if(nums[i] > 0) break

    if(i > 0 && nums[i] == nums[i - 1]){
        continue
    }
    let pairs = find_pair(nums, i+1, -nums[i]);
    for(let pair of pairs){
        answer.push([...pair, nums[i]]);
    }
  }
  return answer;
}

function find_pair(nums, start, target){
    let pairs = []
    let left = start;
    let right = nums.length - 1;

    while(left < right){
        let sum = nums[left] + nums[right];
        if(target === sum){
            pairs.push([nums[left], nums[right]]);
            left += 1;

            while(left < right && nums[left] == nums[left - 1]){
                left += 1;
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
