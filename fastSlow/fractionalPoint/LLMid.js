import {ListNode} from "../../linkedList/ds.js";

function find_middle(head){
    let slow = head;
    let fast = head;

    // fast.next.next -> for detecting first occurance of middle element in case of even number of nodes
    while(fast && fast.next){
        slow = slow.next;
        fast = fast.next.next;
    }
    return slow;
}

const arr = [1, 2, 3, 4]

let head = new ListNode(arr[0]);
let curr = head;

for(let i=1;i<arr.length;i++){
    curr.next = new ListNode(arr[i]);
    curr = curr.next;
}

let num = find_middle(head);
console.log(num.val);
