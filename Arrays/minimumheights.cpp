#include<iostream>
using namespace std;

// Using Sorting - O(nlogn) Time and O(1) Space
// The idea is to sort the array and check the maximum height difference at each index by increasing 
// the height of towers up to that index and decreasing the height of towers beyond that index.

// For any index i, if we add k to all heights in subarray arr[0...i-1] and subtract k from all heights in subarray arr[i...n-1], 
// then we know that smallest height = min(arr[0]+k, arr[i]-k) and tallest height = min(arr[i-1]+k, arr[n-1]-k). 
// So, the smallest difference between tallest height and smallest height over all indices will be the result.

// We can see that for any index i, the smallest height depends on arr[0] and arr[i] and the tallest height depends on arr[i - 1] and arr[n - 1], 
// so instead of modifying the subarrays arr[0...i-1] and arr[i...n-1],
//  we can simply modify arr[0], arr[i - 1], arr[i] and arr[n - 1] to get the smallest difference between heights.

int minimumheights(vector<int>& arr,int k){
    int n = arr.size();
    sort(arr.begin(), arr.end());
  
    // If we increase all heights by k or decrease all
    // heights by k, the result will be arr[n - 1] - arr[0]
    int res = arr[n - 1] - arr[0];
     //  For all indices i, increment arr[0...i-1] by k and
    // decrement arr[i...n-1] by k
    for (int i = 1; i < arr.size(); i++) {
      
        // Impossible to decrement height of ith tower by k, 
        // continue to the next tower
        if (arr[i] - k < 0)
            continue;
      
        // Minimum height after modification
        int minH = min(arr[0] + k, arr[i] - k);
      
        // Maximum height after modification
        int maxH = max(arr[i - 1] + k, arr[n - 1] - k);

        // Store the minimum difference as result
        res = min(res, maxH - minH);
    }
    return res;
}
int main(){
    int k = 6;
    vector<int> arr = {12, 6, 4, 15, 17, 10};

    int ans = minimumheights(arr, k);
    cout << ans;

    return 0;
}