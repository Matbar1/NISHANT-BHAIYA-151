class RandomizedSet {
   
private:
    unordered_map<int, int> hashMap; // stores element -> index mapping
    vector<int> elements; // stores the elements
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (hashMap.find(val) != hashMap.end()) {
            return false; // value already exists
        }
        
        elements.push_back(val); // add the element at the end of the vector
        hashMap[val] = elements.size() - 1; // store its index in the hash map
        return true;
    }
    
    bool remove(int val) {
        if (hashMap.find(val) == hashMap.end()) {
            return false; // value does not exist
        }
        
        int index = hashMap[val]; // get the index of the value
        int lastElement = elements.back(); // get the last element in the vector
        
        // Replace the value at index with the last element
        elements[index] = lastElement;
        hashMap[lastElement] = index;
        
        // Remove the value from the vector and the hash map
        elements.pop_back();
        hashMap.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % elements.size(); // generate a random index
        return elements[randomIndex]; // return the element at the random index
    }
};



/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */