#include<iostream>
#include<vector>
using namespace std;
// [Naive Approach] Generating All Permutations - O(n!*n*log(n!)) Time and O(n!) Space
// The very basic idea that comes to our mind is that we would first generate all possible permutations of a given array and sort them. 
// Once sorted, we locate the current permutation within this list. The next permutation is simply the next arrangement in the sorted order. 
// If the current arrangement is the last in the list then display the first permutation (smallest permutation).

// [Naive Approach] Generating All - O(n!*n*log(n!)) Time and Space - O(n!)
// void permutation(vector<vector<int> >& res, vector<int>& v, int index){
//     //we simply find all the possibilities of the given array
//     if(index  > v.size()-1){//if index value is greater than the 2d vector size then store it in the 2d vector
//         res.push_back(v);//store vector in the 2d vector
//         return ; //return it
//     }

//     //we simply iterate the j to length of the array because we one by one swap these elements by start from index
//     for(int j = index; j < v.size();j++){
//         //swapping the element
//         swap(v[index],v[j]);
//         //recursive call 
//         permutation(res,v,index+1);//increment the index 1 by 1
//         //then backtrack so that at all we increment it by 1
//         swap(v[index],v[j]);
//     }
// }
// void nextpermutation(vector<int>& v){
//     //In the naive approach
//     //Step 1 = make one 2d vector array to store all the possible permutations in the vector
//     vector<vector<int> >res;
//     //Step 2 = make one recursive call to find all the permutations of the given array and store in this 2d vector
//     permutation(res,v,0);
//     //step 3 = simply sort the resultant array 
//     sort(res.begin(),res.end());
//     // for(auto m : res){ for(auto vi : m){cout <<vi<<" ";}cout<<endl; }cout<<endl;//To represent the 2d vector print method
//     //Step 4 = find the vector v in resultant matrix
//     for(int i = 0; i < res.size();i++){
//         //if the matrix find then 
//         if(res[i] == v){
//             //if the location that vector is at end then store res[0] in v
//             if(i == res.size()-1) v = res[0];
//             //and if the location is not at end then next can be store
//             if(i < res.size()-1 ) v = res[i+1];

//             break;
//         }
//     }
// }

// Generating Only Next - O(n) Time and O(1) Space
// Let's try some examples to see if we can recognize some patterns. 

// [1, 2, 3, 4, 5]: next is [1, 2, 3, 5, 4]
// Observation: 4 moves and 5 comes in place of it

// [1, 2, 3, 5, 4]: next is [1, 2, 4, 3, 5]
// Observation: 3 moves, 4 comes in place of it. 3 comes before 5 (mainly 3 and 5 are in sorted order)

// [1, 2, 3, 6, 5, 4]: next is [1, 2, 4, 3, 5, 6]
// Observation: 3 moves, 4 comes in place of it. [3, 5 and 6 are placed in sorted order]

// [3, 2, 1]: next is [1, 2, 3]
// Observation: All elements are reverse sorted. Result is whole array sorted.

// [1, 2, 3, 6, 4, 5]: next is [1, 2, 3, 6, 5, 4]
// Observation: 4 moves and 5 comes in place of it

// Observations of Next permutation: 

// To get the next permutation we change the number in a position which is as right as possible.
// The first number to be moved is the rightmost number smaller than its next.
// The number to come in-place is the rightmost greater number on right side of the pivot.
// Each permutation (except the very first) has an increasing suffix. 
// Now if we change the pattern from the pivot point (where the increasing suffix breaks) to its next possible lexicographic representation
//  we will get the next greater permutation.


// Follow the steps below to implement the above observation:

// Iterate over the given array from end and find the first index (pivot) which doesn't follow property of non-increasing suffix, 
// (i.e,  arr[i] < arr[i + 1]).
// If pivot index does not exist, then the given sequence in the array is the largest as possible. So, reverse the complete array. 
// For example, for [3, 2, 1], the output would be [1, 2, 3]
// Otherwise, Iterate the array from the end and find for the successor (rightmost greater element) of pivot in suffix.
// Swap the pivot and successor
// Minimize the suffix part by reversing the array from pivot + 1 till n.
// void nextpermutation(vector<int>& v){
//     int n = v.size();

//     //Step 1 = find the pivot index
//     int pivot = -1;
//     for(int i = n - 2; i >= 0 ; i--){
//         if(v[i] < v[i+1]){
//             pivot = i;
//             break;
//         }
//     }

//     // Step 2 = If pivot point does not exist, reverse the
//     // whole array
//     if(pivot == -1){
//         reverse(v.begin(),v.end());
//         return ;
//     }

//     //Step 3 = // find the element from the right that
//     // is greater than pivot
//     for(int i = n - 1; i > pivot; i--){
//             if(v[i] > v[pivot]){
//                 swap(v[i],v[pivot]);
//                 break;
//             }
//     }
//     //Step 4 = Reverse rest pivot + 1 element to find next permutation
//     reverse(v.begin() + pivot + 1, v.end());
// }

//using c++ inbuilt function next_permutation
void nextpermutation(vector<int>& v){
    next_permutation(v.begin(),v.end());
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++){
        cin>>v[i];
    }
    nextpermutation(v);
    for(int i : v){
        cout<<i<<" ";
    }
    return 0;
}