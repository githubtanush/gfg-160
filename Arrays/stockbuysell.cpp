// Stock Buy and Sell - Multiple Transaction Allowed
#include<iostream>
#include<vector>
using namespace std;
// [Naive Approach] Using Recursion - Exponential Time
// We consider every valid pair (A pair of indexes i and j such that price[i] < price[j] and j > i),
// we get the profit of the pair as (price[j] - price[i]) and add recursively compute profits for i-1 and j+1. 
// Finally we return the maximum of all profits obtained by all valid pairs.
// int maxprofit(vector<int>& price, int s, int e){
//     int res = 0;
//     //  Consider every valid pair, find the profit with it
//     // and recursively find profits on left and right of it
//     for(int i = s; i < e ; i++){
//         for(int j = i + 1; j <= e ;j++){
//             if(price[j] > price[i]){
//                 int curr = (price[j] - price[i]) + maxprofit(price,s,i-1)+  maxprofit(price,j+1,e);
//                 res = max(res,curr);
//             }
//         }
//     }
//     return res;
// }


// [Better Approach] Local Minima and Maxima - O(n) Time and O(1) Space
// When the prices are going down, we do not do anything and let the prices go down. 
// When the prices reach a local minimum value (a value after which the prices go up), we buy the stock. 
// When the prices are going up, we let the prices go up and once the prices reach a local maxima, we sell the stock.

// The idea is to traverse the array from left to right and do following.

// Find local minima and then a local maxima.
// Compute the difference between two and add to the result.

// int maximumprofit(vector<int>& prices){
//     int n = prices.size();
//     int lmin = prices[0];//Local minima
//     int lmax = prices[0];//Local maxima
//     int res = 0;

//     int i = 0;
//     while(i < n - 1){
//         //Find local minima
//         while(i < n - 1 && prices[i] >= prices[i+1]) i++;
//         lmin = prices[i];

//         //Find local maxima
//         while(i < n - 1 && prices[i] <= prices[i+1]) i++;
//         lmax = prices[i];

//         //Add current profit
//         res = res + ( lmax - lmin );
//     }
//     return res;
// }





// [Expected Approach] Accumulate Profit - O(n) Time and O(1) Space
// This is mainly an optimization over the previous solution. Instead of selling at local maxima, 
// we keep selling while the prices are going up. 
// This way we accumulate the same profit and avoid some condition checks required for computing local minima and maxima.

// Traverse price[] from i = 1 to price.size() - 1

// res = 0
// if price[i] > price[i - 1]
// res = res + price[i] - price[i - 1]
int maximumprofit(vector<int>& prices){
    int res = 0;
  
    // Keep on adding the difference between
    // adjacent when the prices a
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) 
            res += prices[i] - prices[i - 1];
    }
    
    return res;
}
int main(){
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    int profit = maximumprofit(prices);
    cout<<"Maximum Profit is : "<<profit<<endl;
    return 0;
}