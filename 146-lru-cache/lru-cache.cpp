class LRUCache {
private:
    int capacity;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    void moveToFront(int key) {
        auto it = mp[key];
        dll.splice(dll.begin(), dll, it);
    }

public:
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        moveToFront(key);
        return mp[key]->second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            moveToFront(key);
        } else {
            if ((int)dll.size() == capacity) {
                auto last = dll.back();
                mp.erase(last.first);
                dll.pop_back();
            }
            dll.push_front({key, value});
            mp[key] = dll.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */