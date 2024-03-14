

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> items; // Doubly-linked list to store key-value pairs in access order.
    unordered_map<int, list<pair<int, int>>::iterator> cache; // Hash map to store key and iterator to the corresponding item in the list.

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto foundIt = cache.find(key);
        if (foundIt == cache.end()) {
            return -1; // Key not found.
        }
        // Move the accessed item to the front of the list.
        items.splice(items.begin(), items, foundIt->second);
        return foundIt->second->second;
    }

    void put(int key, int value) {
        auto foundIt = cache.find(key);
        if (foundIt != cache.end()) {
            // Update existing item's value and move it to the front of the list.
            foundIt->second->second = value;
            items.splice(items.begin(), items, foundIt->second);
            return;
        }
        // Check if the cache is at capacity.
        if (items.size() == capacity) {
            // Remove the least recently used item from both the list and the hash map.
            auto lru = items.back();
            cache.erase(lru.first);
            items.pop_back();
        }
        // Insert the new item at the front of the list.
        items.emplace_front(key, value);
        // Update the hash map with the new item's iterator.
        cache[key] = items.begin();
    }
};
