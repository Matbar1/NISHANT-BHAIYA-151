/*
    Time Complexity : O(T*N)
    Space Complexity : O(T)

    Where ‘N’ is the number of problem setters, 
    and ‘T’ is the maximum time i.e (10^8) here.
*/


vector<int> findFreeIntervals(vector<vector<int>> &schedules) {
    // Number of Problem Setters.
    int n = schedules.size();
    // Maximum time
    const int MAX = 100000000; 

    // Create a boolean array ‘freeTime’ of size MAX and fill it with true.
    vector<bool> freeTime(MAX+1, true);

    for(int i = 0; i < n; i++) {
        // Mark false at all the time at which setter 'i' is working
        for(int j = 0; j < schedules[i].size(); j+=2) {
            for(int t = schedules[i][j]; t <= schedules[i][j+1]; t++) {
                freeTime[t] = false;
            }
        }
    }

    // Finding intervals where all setters are free and adding them in 'result'
    vector<int> result;
     for(int i = 0; i < freeTime.size(); i++) {
        // Start of interval
        if(freeTime[i] == true && (i == 0 || freeTime[i-1] == false)) {
            result.push_back(i);
        }
        // End of interval
        if(freeTime[i] == true && (i == MAX || freeTime[i+1] == false)) {
            result.push_back(i);
        }
    }
    
    return result;
}