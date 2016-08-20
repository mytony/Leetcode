/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/
// Forum seems to have a better way to locate the key in cache, mine is O(n) right now
class LRUCache{
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        cache.reserve(capacity);
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        } else {
            // update time order
            int i = 0;
            // find position in the cache
            while (cache[i] != key) {
                i++;
            }
            
            cache.erase(cache.begin() + i);
            cache.push_back(key);
            return map[key];
        }
    }
    
    void set(int key, int value) {
        if (map.find(key) == map.end()) {
            if (map.size() >= capacity_) {
                map.erase(cache[0]);
                cache.erase(cache.begin());
            }
            cache.push_back(key);
            map[key] = value;
        } else {
            // how to update the order of key in cache to the latest
            // O(n) way is search the vector value for the key
            int i = 0;
            // find position in the cache
            while (cache[i] != key) {
                i++;
            }
            
            cache.erase(cache.begin() + i);
            cache.push_back(key);
            map[key] = value;
        }
    }
    
private:
    int capacity_;
    vector<int> cache;
    unordered_map<int, int> map;
};