class LRUCache {
public:
    struct ListNode {
        int key;
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode(int k, int v): key(k), val(v), next(nullptr), prev(nullptr) {}
    };

    ListNode *head;
    ListNode *tail;

    int cap;
    unordered_map<int, ListNode*> map;

    void addNode(ListNode *node) {
        ListNode *temp = head->next;

        node->next     = temp;
        node->prev     = head;

        head->next     = node;
        temp->prev     = node;
    }

    void delNode(ListNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    };

    LRUCache(int capacity) {
        cap = capacity;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);

        head->next = tail;
        head->prev = tail;

        tail->next = head;
        tail->prev = head;
    }

    int get(int key) {
        // find key 
        if (map.find(key) == map.end()) return -1;

        // get node
        ListNode *node = map[key];

        // erase map and delete node
        map.erase(key);
        delNode(node);

        //add node and update map
        addNode(node);
        map[key] = head->next;

        //return node;
        return node->val;
    }

    void put(int key, int val) {
        
        // check key already exist
        if (map.find(key) != map.end()) {

            ListNode *node = map[key];

            // delete existing entry            
            delNode(node);
            map.erase(key);
            
            node->val = val;

            // add new entry
            addNode (node);
            map[key] = head->next;


        } else {
        //check key does not exist     

            // check for capacity
            if (map.size() == cap) {
                ListNode *node = tail->prev;
                int key = node->key;

                delNode(node);
                map.erase(key);

                delete node;
            }

            ListNode *node = new ListNode(key, val);
            addNode(node);
            map[key] = node;
        }
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
