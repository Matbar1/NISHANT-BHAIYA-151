#include<bits/stdc++.h>
int Solution::books(vector<int> &A, int B) {
    if(A.size()<B) return -1;
    assert(A.size()<=100000);
    long long min_time = (*max_element(A.begin(), A.end()));
    long long max_time = accumulate(A.begin(), A.end(), 0);
    assert(min_time<=100000);
    long long mid;
    int required=0, time=0;
    while(min_time<=max_time){
        required=1;
        time=0;
        mid = (min_time+max_time)/2;
        for(int i=0; i<A.size(); i++){
            if(time+A[i]>mid){
                time=A[i];
                required++;
            }
            else time+=A[i];
        }
            if(required>B) min_time = mid+1;
            else max_time = mid-1;
    }
    return min_time;
}
