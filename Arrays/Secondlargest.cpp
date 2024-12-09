#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Brute force/Naive approach - with Time Complexity - O(nlogn) and Space Complexity - O(1)
// int secondlargestelement(vector<int>& v){
//     //brute force - sort krke last 2nd element pta kr lunga
//     sort(v.begin(),v.end()); // O(n logn)
//     //return krne ke liye ek int variable ka hona jroori hai
//     int ans = -1;
//     //loop chlakar pta krta hu taaki agr koi duplicate element hai to vo bhi hta sku
//     for(int i = v.size()-2;i>=0;i--){// O(n)
//         if(v[i] < v[v.size()-1]){
//             ans = v[i];
//             break;
//         }
//     }
//     return ans;
// }
//Time complexity - O(n logn + n) = O(nlogn) and Space Complexity - O(1)

//Better approach - Two pass search Time Complexity - O(n) and Space Complexity - O(1)
//In two pass search  - The approach is to traverse the array twice. In the first traversal, find the maximum element. 
//In the second traversal, find the maximum element ignoring the one we found in the first traversal.
// int secondlargestelement(vector<int>& v){
// //step 1 - simply make the variable largest and secondlargest and initialize both of them with -1 or INT_MIN;
// int largest = -1, secondlargest = -1;
// //step 2 - traverse the array and find the largest element
// for(int i = 0; i < v.size();i++)
//     if(v[i] > largest) largest = v[i];
// //step 3 - traverse the array and find the second largest element by ignoring the largest element
// for(int i = 0; i < v.size();i++)
//     if(v[i] > secondlargest && v[i] != largest) secondlargest = v[i];

// //step 4 - return second largest
// return secondlargest;
// }



// Expected approach - The idea is to keep track of the largest and second largest element while traversing the array.
// Initialize largest and second largest with -1. Now, for any index i,
//If arr[i] > largest, update second largest with largest and largest with arr[i].
//Else If arr[i] < largest and arr[i] > second largest, update second largest with arr[i].
int secondlargestelement(vector<int>& v){
    //Step 1 - again make one largest and second largest variable initialize with -1;
    int largest  = -1, secondlargest = -1;
    //Step 2  - On traversing the array check condition if arr[i] > largest then update second largest with largest
    //and largest with arr[i] 
    //and else if condition arr[i] < largest and arr[i] > secondlargest , then update secondlargest with arr[i]

    for(int i = 0; i < v.size();i++){
        if(v[i] > largest){
            secondlargest = largest;
            largest = v[i];
        }
        else if(v[i] < largest && v[i] > secondlargest) secondlargest = v[i];
    }
    //Step 3 - return the secondlargest element
    return secondlargest;
}
int main(){
    vector<int> v;
    int n;
    cin>>n;
    v.resize(n);
    for(int i = 0; i < n;i++){
        cin>>v[i];
    }
    int ans = secondlargestelement(v);
    cout<<"The second largest number in the array is : "<<ans<<endl;
    return 0;
}