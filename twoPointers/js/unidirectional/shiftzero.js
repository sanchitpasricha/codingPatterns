function shift_zeros_to_the_end(nums) {
  let left = 0;

  for(let right=0;right<nums.length;right++){
    if(nums[right] !== 0){
        let temp = nums[right];
        nums[right] = nums[left];
        nums[left] = temp;

        left = left + 1;
    }
  }
}

const nums = [0,1,0,3,2];
shift_zeros_to_the_end(nums);
for(let i=0;i<nums.length;i++){
    console.log(nums[i]);
}
