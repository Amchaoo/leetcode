class LRUCache {
public:
    map<int, int> container;
    int lastVisitedKey;
    int maxCapacity = 1;
    int count = 0;

    LRUCache(int capacity) {
        maxCapacity = capacity;
    }

    int get(int key) {
        if (container[key] == NULL) {
            return -1;
        }

        return container[key];
    }

    void put(int key, int value) {
        if (count == maxCapacity) {
            container.erase(lastVisitedKey);
            count--;
        }

        if (get(key) == -1) {
            container[key] = value;
            conut++;
            lastVisitedKey = key;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */