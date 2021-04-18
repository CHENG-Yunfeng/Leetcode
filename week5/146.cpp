#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>

using namespace std;

// LRU缓存机制
struct DLinkedNode {
    int key, val;
    DLinkedNode* pre;
    DLinkedNode* next;
    DLinkedNode(): key(0), val(0), pre(nullptr), next(nullptr) {}
    DLinkedNode(int key, int val): key(key), val(val), pre(nullptr), next(nullptr) {}
    DLinkedNode(int key, int val, DLinkedNode* pre, DLinkedNode* next): key(key), val(val), pre(pre), next(next) {}  
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size = 0;
    int selfCapacity;
public:
    LRUCache (int capacity): selfCapacity(capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            DLinkedNode* node = cache[key];
            movetohead(node);
            return node->val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addtohead(node);
            size += 1;
            if (size > selfCapacity) {
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        } else {
            DLinkedNode* node = cache[key];
            node->val = value;
            movetohead(node);
        }
    }

    void movetohead(DLinkedNode*& node) {
        removeNode(node);
        addtohead(node);
    }

    void removeNode(DLinkedNode*& node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void addtohead(DLinkedNode*& node) {
        node->next = head->next;
        node->next->pre = node;
        head->next = node;
        node->pre = head;
    }

     DLinkedNode* removeTail() {
        DLinkedNode* node = tail->pre;
        removeNode(node);
        return node;
     }
};

int main() {
    LRUCache lru(2);

    // cout << "put(1, 1)" << lru.put(1, 1) << endl;
    // cout << "put(2, 2)" << lru.put(2, 2) << endl;
    
    cout << "put(1, 1)" << endl;
    lru.put(1, 1);
    cout << "put(2, 2)" << endl;
    lru.put(2, 2);
    cout << "get(1): " << lru.get(1) << endl;
    cout << "put(3, 3)" << endl;
    lru.put(3,3);
    cout << "get(2): " << lru.get(2) << endl;
    cout << "get(3): " << lru.get(3) << endl;
    cout << "get(4): " << lru.get(4) << endl;
}