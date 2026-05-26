function isHappy(n) {
    let slow = n;
    let fast = n;
    while (true) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
        if (fast === 1) {
            return true;
        }
        else if(slow === fast){
            return false;
        }
    }
}

function getNext(n) {
    let totalSum = 0;
    while (n > 0) {
        let d = n % 10;
        totalSum += d * d;
        n = Math.floor(n / 10);
    }   
    return totalSum;
}

console.log(isHappy(116));