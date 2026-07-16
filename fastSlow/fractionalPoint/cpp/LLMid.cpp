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

Node* findMidNode(Node* head){
    Node* fast = head;
    Node* slow = head;

    while(fast->next && fast->next->next){
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}

int main(){
    vector<int> nums = {1,2,4,7};

    Node* head = new Node(nums[0]);
    Node* curr = head;

    for(int i=1;i<nums.size();i++){
        curr -> next = new Node(nums[i]);
        curr = curr -> next;
    }

    Node* ans = findMidNode(head);
    cout<<ans->data;
    return 0;
}