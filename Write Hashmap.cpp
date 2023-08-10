#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class HashMap {
private:
    static const int size = 100;  // Size of the hash table
    std::vector<std::list<std::pair<int, int>>> table;

    // Hash function
    int hash(int key) {
        return key % size;
    }

public:
    HashMap() : table(size) {}

    // Insert a key-value pair into the HashMap
    void insert(int key, int value) {
        int index = hash(key);
        auto& bucket = table[index];

        // Check if the key already exists, and update the value if so
        for (auto& entry : bucket) {
            if (entry.first == key) {
                entry.second = value;
                return;
            }
        }

        // Key doesn't exist, add a new entry
        bucket.push_back(std::make_pair(key, value));
    }

    // Get the value associated with a key
    int get(int key) {
        int index = hash(key);
        auto& bucket = table[index];

        for (const auto& entry : bucket) {
            if (entry.first == key) {
                return entry.second;
            }
        }

        return -1;  // Key not found
    }

    // Remove a key-value pair from the HashMap
    void remove(int key) {
        int index = hash(key);
        auto& bucket = table[index];

        auto entry = std::find_if(bucket.begin(), bucket.end(), [key](const std::pair<int, int>& p) {
            return p.first == key;
        });

        if (entry != bucket.end()) {
            bucket.erase(entry);
        }
    }
};

int main() {
    HashMap hashMap;
    
    hashMap.insert(1, 10);
    hashMap.insert(2, 20);
    hashMap.insert(3, 30);
    
    std::cout << hashMap.get(1) << std::endl;  // Output: 10
    std::cout << hashMap.get(2) << std::endl;  // Output: 20
    
    hashMap.remove(2);
    
    std::cout << hashMap.get(2) << std::endl;  // Output: -1 (key not found)
    
    return 0;
}
