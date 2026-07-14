#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

Node* nodeReversal(Node* head){
    Node* curr = head;
    Node* prev = nullptr;

    while(curr){
        Node* next_node = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next_node;
    }
    return prev;
}

int main(){
    vector<int> nums = {1,2,4,7,3};
    
    Node* head = new Node(nums[0]);
    Node* current = head;

    for(int i=1;i<nums.size();i++){
        current -> next = new Node(nums[i]);
        current = current -> next;
    }

    Node* ans = nodeReversal(head);
    
    while(ans){
        cout<<ans -> data<<" ";
        ans = ans -> next;
    }

    return 0;
}