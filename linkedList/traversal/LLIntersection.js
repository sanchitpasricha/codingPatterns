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

export function linked_list_intersection(head_A, head_B) {
  let ptr_A = head_A;
  let ptr_B = head_B;

  while(ptr_A != ptr_B){
    if(ptr_A){
        ptr_A = ptr_A.next;
    }
    else{
        ptr_A = head_B;
    }

    if(ptr_B){
        ptr_B = ptr_B.next;
    }
    else{
        ptr_B = head_A;
    }

    return ptr_A;
  }
}

const common = new ListNode(8);
common.next = new ListNode(10);

const head_A = new ListNode(3);
head_A.next = new ListNode(7);
head_A.next.next = common;

const head_B = new ListNode(99);
head_B.next = new ListNode(1);
head_B.next.next = common;

const intersection = linked_list_intersection(head_A, head_B);

if (intersection) {
    console.log("Intersection at node value:", intersection.val);
} else {
    console.log("No intersection");
}