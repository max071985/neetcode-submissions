class Node {
public:
    int _key;
    int _val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        _key = key;
        _val = val;
    }
};

class LRUCache {
private:
    int _capacity;
    int _size;
    unordered_map<int, Node*> _cache;
    Node* least_used, *most_used;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _size = 0;
        least_used = new Node(-1, -1);
        most_used = new Node(-2, -1);
        least_used->prev = nullptr;
        least_used->next = most_used;
        most_used->prev = least_used;
        most_used->next = nullptr;
    }
    
    int get(int key) {
        if (_cache.contains(key)) {
            Node* usedNode = _cache[key];
            usedNode->prev->next = usedNode->next;
            usedNode->next->prev = usedNode->prev;

            most_used->prev->next = usedNode;
            usedNode->prev = most_used->prev;
            most_used->prev = usedNode;
            usedNode->next = most_used;
            return _cache[key]->_val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (_cache.contains(key)) {
            Node* toUpdate = _cache[key];
            toUpdate->_val = value;

            toUpdate->prev->next = toUpdate->next;
            toUpdate->next->prev = toUpdate->prev;

            most_used->prev->next = toUpdate;
            toUpdate->prev = most_used->prev;
            toUpdate->next = most_used;
            most_used->prev = toUpdate;
            return;
        }
        if (_size >= _capacity) {
            // remove least recently used
            Node* toRemove = least_used->next;
            least_used->next = toRemove->next;
            toRemove->next->prev = least_used;
            // remove from cache
            _cache.erase(toRemove->_key);
            _size--;
        }
        Node* toAdd = new Node(key, value);
        most_used->prev->next = toAdd;
        toAdd->next = most_used;
        toAdd->prev = most_used->prev;
        most_used->prev = toAdd;
        // Add to cache
        _cache[key] = toAdd;
        _size++;
    }
};
