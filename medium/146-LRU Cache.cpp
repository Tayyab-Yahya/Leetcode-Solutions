class Node {
    public:
        int val;
        int key;
        Node* prev;
        Node* next;

        Node(int k, int v){
            val = v;
            key = k;
            prev = next = NULL;
        }
};

class LRUCache {

    Node* head;
    Node* tail;
    int limit;
    unordered_map<int, Node*> m;

    void addNode(Node* node) {
        Node* oldNext = head->next;
        node->next = oldNext;
        node->prev = head;
        head->next = node;
        oldNext->prev = node;
    }

    void delNode(Node* n) {
        Node* oldNext = n->next;
        Node* oldPrev = n->prev;
        oldNext->prev = oldPrev;
        oldPrev->next = oldNext;

        n->next = NULL; n->prev = NULL;
        delete n;
    }

public:
    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }

        Node* ansNode = m[key];
        int ans = ansNode->val;
        m.erase(key);
        delNode(ansNode);
        Node* newNode = new Node(key, ans);
        addNode(newNode);
        m[key] = newNode;

        return ans;
    }
    
    void put(int key, int val) {
        
        // Key already exists
        if(m.find(key) != m.end()){
            delNode(m[key]);
            m.erase(key);
        }

        // Limit is full
        if(m.size() == limit){
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node* newNode = new Node(key, val);
        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */