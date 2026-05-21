import { ListNode } from "../ds.js";

/**
 * Definition of ListNode:
 * class ListNode {
 *     constructor(val = null, next = null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

function remove_kth_last_node(head, k) {
    let dummy = new ListNode(0);
    dummy.next = head;
    let trailer = dummy;
    let leader = dummy;

    for(let i=0;i<k;i++){
        leader = leader.next;
        if(!leader){
            return head;
        }
    }

    while(leader.next){
        leader = leader.next;
        trailer = trailer.next;
    }

    trailer.next = trailer.next.next;
    return dummy.next;
}

const arr = [1, 2, 4, 7, 3]

let head = new ListNode(arr[0])
let current = head

for (let i = 1; i < arr.length; i++) {
    current.next = new ListNode(arr[i])
    current = current.next
}
let temp = remove_kth_last_node(head,2)
while (temp) {
    console.log(temp.val)
    temp = temp.next
}