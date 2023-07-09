class Solution {
public:
   int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int currPos = 0; // Current position
    int numStops = 0; // Number of stops made
    int fuel = startFuel; // Current fuel in the tank

    // Create a max heap to store the fuel at each station
    priority_queue<int> fuelHeap;

    for (const auto& station : stations) {
        int stationPos = station[0];
        int stationFuel = station[1];

        // Calculate the distance to the next station
        int distance = stationPos - currPos;

        // While the current fuel is not enough to reach the next station
        while (fuel < distance) {
            // If there are no previous stops to refuel from, return -1
            if (fuelHeap.empty()) {
                return -1;
            }

            // Refuel from the station with the maximum fuel
            fuel += fuelHeap.top();
            fuelHeap.pop();
            numStops++;
        }

        // Update the current position and fuel
        currPos = stationPos;
        fuel -= distance;

        // Add the station's fuel to the heap
        fuelHeap.push(stationFuel);
    }

    // Calculate the distance from the last station to the target
    int distance = target - currPos;

    // While the current fuel is not enough to reach the target
    while (fuel < distance) {
        // If there are no previous stops to refuel from, return -1
        if (fuelHeap.empty()) {
            return -1;
        }

        // Refuel from the station with the maximum fuel
        fuel += fuelHeap.top();
        fuelHeap.pop();
        numStops++;
    }

       return numStops;
   }
};