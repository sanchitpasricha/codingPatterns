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

bool checkCycle(Node* head){
    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next){
        fast = fast -> next -> next;
        slow = slow -> next;
        if(fast && slow){
            return true; 
        }
    }
    return false;
}

int main(){
    vector<int> nums = {0,1,2,3,4};

    Node* head = new Node(nums[0]);
    Node* curr = head;

    for(int i=1;i<nums.size();i++){
        curr -> next = new Node(nums[i]);
        curr = curr -> next;
    }

    curr -> next = head;
    bool ans = checkCycle(head);
    cout<<ans;

    return 0;

}