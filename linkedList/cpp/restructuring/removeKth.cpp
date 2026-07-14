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

Node* removeEle(Node* head, int k){
    Node* dummy = new Node(-1);
    dummy = head;

    Node* trailer = dummy;
    Node* leader = dummy;

    for(int i=0;i<k;i++){
        leader = leader -> next;
    }

    while(leader->next){
        leader = leader -> next;
        trailer = trailer -> next;
    }

    trailer -> next = trailer -> next -> next;
    return dummy;

}

int main(){
    vector<int> nums = {1,2,4,7,3};

    Node* head = new Node(nums[0]);
    Node* curr = head;

    for(int i=1; i<nums.size(); i++){
        curr -> next = new Node(nums[i]);
        curr = curr -> next;
    }

    Node* ans = removeEle(head, 2);

    while(ans){
        cout<<ans -> data<<" ";
        ans = ans -> next;
    }

    return 0;
}