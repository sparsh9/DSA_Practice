class LRUCache {
public:
    int count=0;
    list<pair<int,int>> lru;

    LRUCache(int capacity) {
        int count = capacity;

    }
    
    int get(int key) {
        for(auto i:lru){
            if(i.first == key){
                return i.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        // if capacity is full, then pop the last element
        if(count >1){
            lru.pop_back();
            count--;
        }
        // push the new (key,value) pair
        lru.push_back(make_pair(key,value));
        count++;
    }
};