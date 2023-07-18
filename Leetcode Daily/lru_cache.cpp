class LRUCache {
public:
    unordered_map<int, pair<list<int>::iterator, int>> ht; // Hash table to store key-value pairs and their corresponding iterator in the list
    list<int> dll; // Doubly linked list to maintain the order of recently used keys
    int cap; // Capacity of the cache
    
    LRUCache(int capacity) {
        cap = capacity; // Initialize the capacity of the cache
    }
    
    // Function to move the given key to the front of the doubly linked list
    void moveToFirst(int key){
        dll.erase(ht[key].first); // Remove the iterator of the key from its current position in the list
        dll.push_front(key); // Push the key to the front of the list
        ht[key].first = dll.begin(); // Update the iterator of the key in the hash table to its new position
    }
    
    // Function to get the value corresponding to the given key
    int get(int key) {
        if(ht.find(key) == ht.end()) // If the key is not found in the hash table
            return -1; // Return -1
        
        moveToFirst(key); // Move the key to the front of the list as it is accessed
        return ht[key].second; // Return the corresponding value
    }
    
    // Function to insert or update a key-value pair in the cache
    void put(int key, int value) {
        if(ht.find(key) != ht.end()){ // If the key already exists in the cache
            ht[key].second = value; // Update the value of the existing key
            moveToFirst(key); // Move the key to the front of the list as it is accessed again
        }
        else{ // If the key is not present in the cache
            dll.push_front(key); // Push the key to the front of the list
            ht[key] = {dll.begin(), value}; // Add the key-value pair to the hash table
            cap--; // Decrement the capacity as a new key is added
            
            if(cap < 0){ // If the capacity exceeds the specified limit
                ht.erase(dll.back()); // Remove the least recently used key-value pair from the hash table
                dll.pop_back(); // Remove the least recently used key from the back of the list
                cap++; // Increment the capacity as a key-value pair is removed
            }
        }
    }
};

/*
Algorithm Outline:

LRUCache()
1. ht: key -> (iterator, value)
2. dll: List to contain keys
3. cap = capacity

Get
1. If key is found, move the key to the front of the list and return the corresponding value. Else, return -1.

Put
1. If the key already exists, update its value and move it to the front of the list.
2. If the key is new, add it to the front of the list, update the hash table with its iterator and value, and decrement the capacity.
3. If the capacity exceeds the specified limit, remove the least recently used key-value pair from the hash table and the back of the list.
*/
