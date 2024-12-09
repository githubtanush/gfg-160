#include<iostream>
#include<vector>
using namespace std;
//move zeroes at the end without changing the order of elements
//brute approach  / Naive approach  - Time Complexity - O(N) and Space Complexity - O(N)
// The idea is to create a temporary array of same size as the input array arr[].
// First, copy all non-zero elements from arr[] to the temporary array.
// Then, fill all the remaining positions in temporary array with 0.
// Finally, copy all the elements from temporary array to arr[].
// void moveallzeroatend(vector<int>& v){
//     //Step 1 = create one more temp array with same size
//     vector<int> temp(v.size());
//     //Step 2 = make one index variable to keep track of the temp array 
//     int index = 0;
//     //Step 3 = traverse the array and enter all non - zero element in the temporary array
//     //by applying the condition v[i] != 0
//     for(int i = 0; i < v.size();i++){
//         if(v[i]!=0) temp[index++] = v[i];
//     }
//     //Step 4 = again start loop and its acting till end till all rest elements fill with 0
//     while(index < v.size()) temp[index++] = 0;
//     //Step 5 - copy all the temporary array to the original vector v[i]
//     v = temp;
// }



//Better approach - Time Complexity - O(N)  && Space Complexity - O(1)
// The idea is to move all the zeros by traversing the array twice.

// First Traversal: Shift non-zero elements
// Traverse the array and maintain the count of non-zero elements. This count is initialized with 0 and keeps track of where the next non-zero element should be placed in the array.
// If the element is non-zero, place it at arr[count] and increment count by 1.
// After traversing all the elements, all non-zero elements will be shifted to the front while maintaining their original order.
// Second Traversal: Fill remaining positions with zeros

// After the first traversal, all non-zero elements will be at the start of the array and count will store the index where the first zero should be placed.
// Iterate from count to the end of array and fill all indices with 0.
// void moveallzeroatend(vector<int>& v){
//     //Step 1 - make one count variable and initialize it with zero and take track of non - zero elements
//     int count = 0;
//     //Step 2 - traverse the array and set all the non - zero elements with firstly in v vector with the help of count variable
//     //if(v[i]!= 0)
//     for(int i = 0; i < v.size();i++){
//         if(v[i]!=0){
//             v[count++] = v[i];
//         }
//     }
//     //Step 3  - till count index to at the end of the array filled all value with zero
//     while(count < v.size()){
//         v[count++] = 0;
//     }
// }


//Expected approach  with Time Complexity - O(N) and Space Complexity - O(1)
// The idea is similar to the previous approach where we took a pointer, say count to track where the next non-zero element should be placed. 
// However, on encountering a non-zero element, instead of directly placing the non-zero element at arr[count],
// we will swap the non-zero element with arr[count]. This will ensure that if there is any zero present at arr[count], 
// it is pushed towards the end of array and is not overwritten.

// void moveallzeroatend(vector<int>& v){
//     //Step 1 - make one pointer to track the position of non - zero element in the array 
//     int count  = 0;
//     //Step 2 - make a for loop and traverse the array where non - zero element is in the array swap this so that 0 reach at end
//     for(int i = 0; i < v.size();i++){
//         if(v[i] != 0){
//             //swap the current element with the 0 at index 'count'
//             swap(v[i],v[count]);
//             //make the count pointer to move next ahead
//             count++;
//         }
//     }
// }




//by using library methods
// In C++, there exists a method stable_parition() that we can directly use here to implement the above method.
void moveallzeroatend(vector<int>& v){
    stable_partition(v.begin(),v.end(), [](int n) {return n != 0; });
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++){
        cin>>v[i];
    }
    moveallzeroatend(v);
    for(auto i : v){
        cout<<i<<" ";
    }
    return 0;
}
// 8  
// 1 0 3 0 5 4 0 0 