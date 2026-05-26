import {ListNode} from '../../linkedList/ds.js'

// Floyd’s Tortoise and Hare Algorithm
function detect_cycle(head){
    let slow = head;
    let fast = head;

    while(fast && fast.next){
        slow = slow.next;
        fast = fast.next.next;

        if(slow === fast){
            return true;
        }
    }
    return false;
}

const arr = [1, 2, 3, 4, 5]

let head = new ListNode(arr[0])
let curr = head

const nodes = [head]

for (let i = 1; i < arr.length; i++) {
    curr.next = new ListNode(arr[i])
    curr = curr.next
    nodes.push(curr)
}

curr.next = nodes[2]

console.log(detect_cycle(head))