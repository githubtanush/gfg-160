//kadane's Algorithm
#include<iostream>
#include<vector>
using namespace std;
// [Naive Approach] By iterating over all subarrays - O(n^2) Time and O(1) Space
// find all subarray sum
// The idea is to run two nested loops to iterate over all possible subarrays and find the maximum sum. 
// The outer loop will mark the starting point of a subarray and inner loop will mark the ending point of the subarray.
// int maximumsubarray(vector<int>& v){
//         int res = v[0];
//     for(int i = 0; i < v.size();i++){
//         int currsum = 0;
//         for(int j = i ; j < v.size();j++) {
//             currsum += v[j];
//         //update if currsum is greater than the res
//         res = max(res,currsum);
//         }
//     }
//     return res;
// }


// [Expected Approach] Using Kadane's Algorithm - O(n) Time and O(1) Space
// The idea of Kadane's algorithm is to traverse over the array from left to right and for each element, 
// find the maximum sum among all subarrays ending at that element. The result will be the maximum of all these values.

// But, the main issue is how to calculate maximum sum among all the subarrays ending at an element in O(1) time?

// To calculate the maximum sum of subarray ending at current element, say maxEnding, we can use the maximum sum ending at the previous element. So for any element, we have two choices:

// Choice 1: Extend the maximum sum subarray ending at the previous element by adding the current element to it. If the maximum subarray sum ending at the previous index is positive, then it is always better to extend the subarray.
// Choice 2: Start a new subarray starting from the current element. If the maximum subarray sum ending at the previous index is negative, it is always better to start a new subarray from the current element.
// This means that maxEnding at index i = max(maxEnding at index (i - 1) + arr[i], arr[i]) and the maximum value of maxEnding at any index will be our answer.

int maximumsubarray(vector<int>& v){
        //Store v[0] in resultant
        int res = v[0];
        // maxending at starting element
        int maxending = v[0];
        //traverse the array and find the maximum sum
        for(int i = 1; i < v.size();i++){
            //find the maximum subarray sum ending at index i by either extending
            //the maximum subarray sum ending at index i - 1 or by 
            //starting the newsubarray from index i;
            maxending = max(maxending+v[i],v[i]);

            //update res if maximum subarray sum ending at index i > res
            res = max(res,maxending);
        }
        return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++){
        cin>>v[i];
    }
    int ans = maximumsubarray(v);
    cout<<"The maximum sum of subarray is : "<<ans<<endl;


    return 0;
}
// 7
// 2 3 -8 7 -1 2 3