class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    unordered_map<int, int> hash;
    	for (int i = 0; i < n; i++) {
    		int numberToFind = x - arr[i];
                //if numberToFind is found in map, return them
    		if (hash.find(numberToFind) != hash.end()) {
    		    return true;
    		}
                //number was not found. Put it in the map.
    		hash[arr[i]] = i;
    	}
    	return false;
	}
};