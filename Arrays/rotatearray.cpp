#include<iostream>
#include<vector>
using namespace std;
// [Naive Approach] Rotate one by one - O(n * d) Time and O(1) Space
// In each iteration, shift the elements by one position to the left in a circular fashion (the first element becomes the last).
// Perform this operation d times to rotate the elements to the left by d positions.

// void rotate(vector<int>& v,int d){
//     //Step 1 = take the size of the array into one variable
//     int n = v.size();
//     //Step 2 = By one one rotation till d rotations
//     for(int i = 0; i < d;i++){
//         //Step 3 = store the first element of the array in one variable
//         int first = v[0];
//         //Step 4 = left rotate the array 
//         for(int i = 0; i < n - 1;i++){
//             v[i] = v[i+1];
//         }
//         v[n-1] = first;
//     }
// }


// [Better Approach] Using Temporary Array - O(n) Time and O(n) Space
// This problem can be solved using the below idea:

// The idea is to use a temporary array of size n, where n is the length of the original array. 
// If we left rotate the array by d positions, the last n - d elements will be at the front and the first d elements will be at the end.

// Copy the last (n - d) elements of original array into the first n - d positions of temporary array.
// Then copy the first d elements of the original array to the end of temporary array.
// Finally, copy all the elements of temporary array back into the original array.
// void rotate(vector<int>& arr,int d){
//      int n = arr.size();

//     // Handle case when d > n
//     d %= n;
  
//     // Storing rotated version of array
//     vector<int> temp(n);

//     // Copy last n - d elements to the front of temp
//     for (int i = 0; i < n - d; i++)
//         temp[i] = arr[d + i];

//     // Copy the first d elements to the back of temp
//     for (int i = 0; i < d; i++)
//         temp[n - d + i] = arr[i];

//     // Copying the elements of temp in arr
//     // to get the final rotated vector
//     for (int i = 0; i < n; i++)
//         arr[i] = temp[i];
// }



//  Approach 2 Using Reversal Algorithm - O(n) Time and O(1) Space
// The idea is based on the observation that if we left rotate the array by d positions, the last (n - d) elements will be at the front and the first d elements will be at the end.

// Reverse the subarray containing the first d elements of the array.
// Reverse the subarray containing the last (n - d) elements of the array.
// Finally, reverse all the elements of the array.

// void rotate(vector<int>& arr, int d){
//    int n = arr.size();
  
//     // Handle the case where d > size of array
//     d %= n;
  
//     // Reverse the first d elements
//     reverse(arr.begin(), arr.begin() + d);

//     // Reverse the remaining n-d elements
//     reverse(arr.begin() + d, arr.end());
  
//     // Reverse the entire array
//     reverse(arr.begin(), arr.end());
// }



// Approach Using Juggling Algorithm - O(n) Time and O(1) Space
// The idea is to use Juggling Algorithm which is based on rotating elements in cycles. 
// Each cycle is independent and represents a group of elements that will shift among themselves during the rotation. 
// If the starting index of a cycle is i, then next elements of the cycle can be found at indices (i + d) % n, (i + 2d) % n, (i + 3d) % n ... 
// and so on till we return to the original index i.
// So for any index i, we know that after rotation, the element that will occupy this position is arr[(i + d) % n].
// Consequently, for every index in the cycle, we will place the element that should be in that position after the rotation is completed.
void rotate(vector<int>& v,int d){
    int n = v.size();
    vector<int> ans(v.size());
    for(int index = 0; index < n;index++){
        int newindex = (index + d) % n;
        ans[index] = v[newindex];
    }
    for(int i : ans) cout<<i<<" ";
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++){
        cin>>v[i];
    }
    int d;
    cin>>d;
    rotate(v,d);
     
    // for(auto i : v){
    //     cout<<i<<" ";
    // }
    return 0;
}
// 6
// 1 2 3 4 5 6
// 2