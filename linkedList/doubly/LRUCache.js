class DoublyLinkedList {
    constructor(key, value) {
        this.key = key;
        this.val = value;
        this.next = null;
        this.prev = null;
    }
}

class LRUCache {
    constructor(capacity) {
        this.capacity = capacity;
        this.hashmap = {};

        this.head = new DoublyLinkedList(-1, -1);
        this.tail = new DoublyLinkedList(-1, -1);

        this.head.next = this.tail;
        this.tail.prev = this.head;
    }

    remove_node(node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    add_to_tail(node) {
        let prevNode = this.tail.prev;

        prevNode.next = node;
        node.prev = prevNode;

        node.next = this.tail;
        this.tail.prev = node;
    }

    get(key) {
        if (!(key in this.hashmap)) {
            return -1;
        }

        let node = this.hashmap[key];

        this.remove_node(node);
        this.add_to_tail(node);

        return node.val;
    }

    put(key, value) {

        if (key in this.hashmap) {
            let existingNode = this.hashmap[key];

            this.remove_node(existingNode);
            delete this.hashmap[key];
        }

        let newNode = new DoublyLinkedList(key, value);

        this.add_to_tail(newNode);
        this.hashmap[key] = newNode;

        if (Object.keys(this.hashmap).length > this.capacity) {

            let lru = this.head.next;

            this.remove_node(lru);
            delete this.hashmap[lru.key];
        }
    }
}