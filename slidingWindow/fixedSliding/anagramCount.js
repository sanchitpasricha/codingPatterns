function countAnagrams(a, b) {
    let count = 0;
    let map = new Map();
    for (let i = 0; i < b.length; i++) {
        let char = b[i];
        map.set(char, (map.get(char) || 0) + 1);
    }
    let left = 0;
    for (let right = 0; right < a.length; right++) {
        let char = a[right];
        if (map.has(char)) {
            map.set(char, map.get(char) - 1);
        }
        while (isAnagram(map)) {
            if (right - left + 1 === b.length) {
                count++;
            }
            let leftChar = a[left];
            if (map.has(leftChar)) {
                map.set(leftChar, map.get(leftChar) + 1);
            }
            left++;
        }
    }
    return count;
}

function isAnagram(map) {
    for (let value of map.values()) {
        if (value > 0) {
            return false;
        }
    }   
    return true;
}

let a = 'aaababa';
let b = 'aba';
const count  = countAnagrams(a, b);
console.log(count);


