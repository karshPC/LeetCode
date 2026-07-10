class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node* prev;

        public:
        Node(int key1, int val1){
            key = key1;
            val = val1;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int cap;

    unordered_map <int, Node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;    
    }

    void insertNodeAfterHead(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode){
        Node* prev = delNode->prev;
        Node* next = delNode->next;
        prev->next = next;
        next->prev = prev;
    }
    
    int get(int key) {
        if (mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            int res = node->val;
            mpp.erase(key);
            deleteNode(node);
            insertNodeAfterHead(node);
            mpp[key] = head->next;
            return res;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            mpp.erase(key);
            deleteNode(node);
        }

        if (mpp.size() == cap) {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        insertNodeAfterHead(new Node(key, value));
        mpp[key] = head->next;
    }
};

