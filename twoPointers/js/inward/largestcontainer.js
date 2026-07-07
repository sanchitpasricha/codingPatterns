function largest_container(heights) {
    let max_volume = 0;
    let left = 0;
    let right = heights.length - 1;

    while (left < right) {
        let water = Math.min(heights[left], heights[right]) * (right - left);
        max_volume = Math.max(max_volume, water);

        if (heights[left] < heights[right]) {
            left = left + 1;
        }
        else if (heights[right] < heights[left]) {
            right = right - 1;
        }
        else {
            right = right - 1;
            left = left + 1;
        }
    }
    return max_volume;
}

const heights = [2,7,8,3,7,6];
const max_volume = largest_container(heights);
console.log(max_volume);
