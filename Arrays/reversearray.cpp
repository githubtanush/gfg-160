#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// [Naive Approach] Using a temporary array - O(n) Time and O(n) Space
// The idea is to use a temporary array to store the reverse of the array.

// Create a temporary array of same size as the original array.
// Now, copy all elements from original array to the temporary array in reverse order.
// Finally, copy all the elements from temporary array back to the original array.
// void reverseArray(vector<int>& arr){
// int n = arr.size();
    
//     // Temporary array to store elements in reversed order
//     vector<int> temp(n);
  
//     // Copy elements from original array to temp in reverse order
//     for(int i = 0; i < n; i++)
//         temp[i] = arr[n - i - 1];
  
//     // Copy elements back to original array
//     for(int i = 0; i < n; i++)
//         arr[i] = temp[i];
// }


// [Expected Approach - 1] Using Two Pointers - O(n) Time and O(1) Space
// The idea is to maintain two pointers: left and right, 
// such that left points at the beginning of the array and right points to the end of the array.

// While left pointer is less than the right pointer, swap the elements at these two positions. 
// After each swap, increment the left pointer and decrement the right pointer to move towards the center of array. 
// This will swap all the elements in the first half with their corresponding element in the second half.
// function to reverse an array
// void reverseArray(vector<int> &arr) {
  
//     // Initialize left to the beginning and right to the end
//     int left = 0, right = arr.size() - 1;
  
//     // Iterate till left is less than right
//     while(left < right) {
      
//         // Swap the elements at left and right position
//         swap(arr[left], arr[right]);
      
//         // Increment the left pointer
//         left++;
      
//         // Decrement the right pointer
//         right--;
//     }
// }



// [Expected Approach - 2] By Swapping Elements - O(n) Time and O(1) Space
// The idea is to iterate over the first half of the array and swap each element with its corresponding element from the end. 
// So, while iterating over the first half, any element at index i is swapped with the element at index (n - i - 1).
// function to reverse an array
// void reverseArray(vector<int> &arr) {
//     int n = arr.size();
//     // Iterate over the first half and for every index i,
//     // swap arr[i] with arr[n - i - 1]
//     for(int i = 0; i < n/2; i++) {
//         swap(arr[i], arr[n - i - 1]);
//     }
// }


// [Alternate Approach] Using Recursion - O(n) Time and O(n) Space
// The idea is to use recursion and define a recursive function that takes a range of array elements as input and reverses it. 
// Inside the recursive function,

// Swap the first and last element.
// Recursively call the function with the remaining subarray.
// recursive function to reverse an array from l to r
// void reverseArrayRec(vector<int> &arr, int l, int r) {
//     if(l >= r)
//         return;
  
//     // Swap the elements at the ends
//     swap(arr[l], arr[r]);
  
//     // Recur for the remaining array
//     reverseArrayRec(arr, l + 1, r - 1);
// }

// // function to reverse an array
// void reverseArray(vector<int> &arr) {
//     int n = arr.size();
//     reverseArrayRec(arr, 0, n - 1);
// }

// Using Inbuilt Methods - O(n) Time and O(1) Space
// function to reverse an array
void reverseArray(vector<int> &arr) {
    reverse(arr.begin(), arr.end());
}

int main(){
    vector<int> arr = { 1, 4, 3, 2, 6, 5 };

    reverseArray(arr);
  
    for(int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}