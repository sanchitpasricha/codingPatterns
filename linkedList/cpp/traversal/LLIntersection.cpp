#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

Node* intersection(Node* head1, Node* head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while(ptr1 != ptr2){
        ptr1 = ptr1 ? ptr1->next : head2;
        ptr2 = ptr2 ? ptr2->next : head1;
    }
    return ptr1;
}

int main() {

    // Common/intersection part: 7 -> 8 -> 9
    Node* common = new Node(7);
    common->next = new Node(8);
    common->next->next = new Node(9);


    // Linked List 1: 1 -> 2 -> 3 -> 7 -> 8 -> 9
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    // Connect List 1 to common node
    head1->next->next->next = common;


    // Linked List 2: 4 -> 5 -> 7 -> 8 -> 9
    Node* head2 = new Node(4);
    head2->next = new Node(5);

    // Connect List 2 to the SAME common node
    head2->next->next = common;
    Node* ans = intersection(head1, head2);
    cout<<ans->data;

    return 0;
}