class LFUCache {
private:
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyValueFreq;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> keyIter;

    void updateFreq(int key) {
        int freq = keyValueFreq[key].second;
        freqList[freq].erase(keyIter[key]);

        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        keyValueFreq[key].second++;
        freqList[freq + 1].push_front(key);
        keyIter[key] = freqList[freq + 1].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0 || keyValueFreq.find(key) == keyValueFreq.end())
            return -1;
        updateFreq(key);
        return keyValueFreq[key].first;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyValueFreq.find(key) != keyValueFreq.end()) {
            keyValueFreq[key].first = value;
            updateFreq(key);
            return;
        }

        if ((int)keyValueFreq.size() == capacity) {
            int keyToRemove = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            if (freqList[minFreq].empty())
                freqList.erase(minFreq);
            keyValueFreq.erase(keyToRemove);
            keyIter.erase(keyToRemove);
        }

        keyValueFreq[key] = {value, 1};
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */