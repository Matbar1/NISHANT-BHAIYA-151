#import <queue>

long long int minimumCostToConnectSticks(vector<int> &arr) {
     // Write your Code here.

     // Create a min heap
     priority_queue<long long, vector<long long>, greater<long long> > pq;

     // Push all the value from vector to heap
     for(int i =0; i<arr.size(); i++)
          pq.push(arr[i]);

     long long cost =0;

     // Calculate the cost of two mini's and push back the sum
     while(pq.size()>1)
     {
          long long a = pq.top();
          pq.pop();
          long long b = pq.top();
          pq.pop();

          long long sum = a+b;
          cost = cost + sum;
          pq.push(sum); // Pushback the sum to heap

     }
     return cost;
}