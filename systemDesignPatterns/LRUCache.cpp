#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val){
        this -> key = key;
        this -> val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache{
    private: 
    int capacity;
    unordered_map<int, Node*> cache;
    Node* tail;
    Node* head;

    public:
    LRUCache(int capacity){
            this -> capacity = capacity;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            tail -> prev = head;
            head -> next = tail;
    }

    void addToTail(Node* n){
        Node* prevNode = tail -> prev;
        n -> prev = prevNode;
        n -> next = tail;
        prevNode -> next = n;
        tail -> prev = n;
    }

    void removeNode(Node* node){
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }

    int get(int key){
        if(cache.find(key) == cache.end()){
            return -1;
        }

        removeNode(cache[key]);
        addToTail(cache[key]);
        return cache[key] -> val;
    }

    void put(int key, int val){
        if(cache.find(key) != cache.end()){
            Node* old = cache[key];
            removeNode(old);
            cache.erase(key);
            delete old;
        }
        Node* node = new Node(key, val);
        cache[key] = node;
        if(cache.size() > capacity){
            Node* lru = head->next;
            cache.erase(lru->key);
            removeNode(lru);
            delete lru;     
        }
        addToTail(node);
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl;   // 10

    cache.put(3, 30);               // Evicts least recently used key

    cout << cache.get(2) << endl;   // Should be -1 if eviction works

    cache.put(4, 40);               // Evicts another key

    cout << cache.get(1) << endl;   // -1
    cout << cache.get(3) << endl;   // 30
    cout << cache.get(4) << endl;   // 40

    return 0;
}

