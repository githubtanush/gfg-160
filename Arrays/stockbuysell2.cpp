// Stock Buy and Sell - Max one Transaction Allowed
#include<iostream>
#include<vector>
using namespace std;
// [Naive Approach] By exploring all possible pairs - O(n^2) Time and O(1) Space
// The idea is to use two nested loops to explore all the possible ways to buy and sell stock. 
// The outer loop decides the day to buy the stock and the inner loop decides the day to sell the stock.
//  The maximum difference between the selling price and buying price between every pair of days will be our answer.
// int maximumprice(vector<int>& prices){
//     int n = prices.size();
//     int res = 0;
//     // Explore all possible ways to buy and sell stock
//     for(int i = 0; i < n - 1 ;i++){
//         for(int j = i+1; j < n;j++){
//             res = max(res,prices[j]-prices[i]);
//         }
//     }
//     return res;
// }

// [Expected Approach] One Traversal Solution - O(n) Time and O(1) Space
// In order to maximize the profit, we need to minimize the cost price and maximize the selling price. So at every step, 
// we keep track of the minimum buy price of stock encountered so far. 
// For every price, we subtract with the minimum so far and if we get more profit than the current result, we update the result.
int maximumprice(vector<int>& prices){
    int n = prices.size();
     int minSoFar = prices[0], res = 0;
     for(int i=1 ; i < n;i++){
         // Update the minimum value seen so
        // far if we see smaller
         minSoFar = min(minSoFar, prices[i]);

          // Update result if we get more profit                
        res = max(res, prices[i] - minSoFar);
     }
       return res;

}
int main(){
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    cout << maximumprice(prices) << endl;
    return 0;
}