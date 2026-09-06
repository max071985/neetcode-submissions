/*
Explanation:
Data structures used: DLL, HASHMAP
    cache elements are stored in a DLL [key,value] pairs size: O(n)
    hashmap with <key, pointer_to_node> size: O(n)
    *where n is cache size

DLL allows for O(1) inserts, deletions from front and back 
(front = least recently used, back = most recently used)

when get/put are called, the key is pushed to the back (if exists on get)
when a put operation happens on a full cache then the front gets removed, new elem is put in the back.

Complexity:
Time: O(1) get, O(1) put
Space: O(n) cache + nodes
*/
class Node {
public:
    int val;
    int key;
    Node* prev;
    Node* next;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node* dummy_least;
    Node* dummy_most;
    int cache_size;
    int elem_count;
public:
    LRUCache(int capacity) {
        cache_size = capacity;
        elem_count = 0;
        dummy_least = new Node(-1,0);
        dummy_most = new Node(-1,0);
        dummy_least->next = dummy_most;
        dummy_most->prev = dummy_least;
    }
    
    int get(int key) {
        if (cache.contains(key)) {
            // Push the node to most recently used:
            Node* node = cache[key];

            // Remove from place in dll
            node->prev->next = node->next;
            node->next->prev = node->prev;

            // Add at the end
            dummy_most->prev->next = node;
            node->prev = dummy_most->prev;

            dummy_most->prev = node;
            node->next = dummy_most;

            return cache[key]->val;    
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            // Update value and push the node to most recently used:
            Node* node = cache[key];
            node->val = value;
            
            // Remove from place in dll
            node->prev->next = node->next;
            node->next->prev = node->prev;

            // Add at the end
            dummy_most->prev->next = node;
            node->prev = dummy_most->prev;

            dummy_most->prev = node;
            node->next = dummy_most;
        }
        else {
            // Add a new value
            Node* newNode = new Node(key, value);
            if (elem_count >= cache_size) {
                // remove the LRU element
                cache.erase(dummy_least->next->key);
                dummy_least->next = dummy_least->next->next;
                dummy_least->next->prev = dummy_least;
                elem_count--;
            }
            // Add the new node to the end
            newNode->prev = dummy_most->prev;
            dummy_most->prev->next = newNode;
            newNode->next = dummy_most;
            dummy_most->prev = newNode;
            cache[key] = newNode;
            elem_count++;
        }
    }
};
