import { ListNode } from '../ds.js'
/**
 * Definition of ListNode:
 * class ListNode {
 *     constructor(val = null, next = null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

function linked_list_reversal(head) {
  let prev_node = null;
  let current_node = head;

  while(current_node){
    let next_node = current_node.next;
    current_node.next = prev_node;
    prev_node = current_node;
    current_node = next_node
  }
  return prev_node;
}

const arr = [1, 2, 4, 7, 3]

let head = new ListNode(arr[0])
let current = head

for (let i = 1; i < arr.length; i++) {
    current.next = new ListNode(arr[i])
    current = current.next
}
let temp = linked_list_reversal(head)
while (temp) {
    console.log(temp.val)
    temp = temp.next
}