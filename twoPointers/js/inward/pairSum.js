function pair_sum_sorted(nums, target) {
    const answer = [];
    let start = 0;
    let end = nums.length - 1;

    while (start < end) {
        let sum = nums[start] + nums[end];
        if (sum === target) {
            answer.push(start, end);
            break
        }
        else if (sum > target) {
            end = end - 1;
        }
        else {
            start = start + 1;
        }
    }
    return answer;
}


const nums = [1, 2, 3, 4, 5, 6];
const target = 7;
const result = pair_sum_sorted(nums, target);
console.log("Pairs:", result);