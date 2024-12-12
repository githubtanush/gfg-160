#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// [Naive Approach] Using Nested Loops - O(n^2) Time and O(1) Space
// The idea is to iterate over all elements and count the frequency of the element in the array. 
// If the frequency of the element is greater than floor(n/3), add it to the result. To avoid adding duplicate elements into the result,
// we can check if the element is already present in the result. We can stop the iteration if we have already found two majority elements.
//function to find majority elements in the array 
// vector<int> findmajority(vector<int>& v){
//     int n = v.size();
//     vector<int> res;
//     for(int i = 0; i < n;i++){
//         //count the frequency of the array
//         int cnt = 0;
//         for(int j = i ; j < n;j++){
//             if(v[j] == v[i]) cnt+=1;
//         }

//         //check if v[i] is a majority element
//             if(cnt > n/3){
//                 //Add v[i] only if it is not already
//                 //present in the result
//                 if(res.size()==0 || v[i] != res[0]){
//                         res.push_back(v[i]);
//                 }
//             }

//             //if we have found 2 majority elements we can stop our search
//             if(res.size() == 2){
//                 if(res[0] > res[1]){
//                     swap(res[0],res[1]);
//                 }
//                 break;
//             }
//     }
//     return res;
// }


// [Better Approach] Using Hash Map or Dictionary - O(n) Time and O(n) Space
// The idea is to use a hash map or dictionary to count the frequency of each element in the array. 
// After counting, iterate over the hash map and if the frequency of any element is greater than (n/3), push it into the result. 
// Finally, the majority elements are returned after sorting.

// vector<int> findmajority(vector<int>& v){
//     int n = v.size();
//     unordered_map<int,int> freq;
//     vector<int> res;
//     //find the frequency of each element in the array
//     for(int ele : v) freq[ele]++;
//     //iterate over the key value pair in hash - map
//     for(auto it : freq){
//         int ele = it.first;
//         int cnt = it.second;
//         //add the element to the result if the frequency is greater than (n/3)
//         if(cnt > n/3) res.push_back(ele);
//     }
//     if(res.size()==2 && res[0] > res[1]) swap(res[0],res[1]);
//     return res;
// }



// [Expected Approach] Boyer-Moore’s Voting Algorithm - O(n) Time and O(1) Space
// The idea is based on the observation that there can be at most two majority elements, which appear more than n/3 times. 
// so we can use Boyer-Moore’s Voting algorithm. 
// As we iterate the array, We identify potential majority elements by keeping track of two candidates and their respective counts.

// Steps:

// Initialize two variables ele1 = -1 and ele2 = -1, for candidates and two variables cnt1 = 0 and cnt2 = 0, for counting.
// In each iteration,
// If an element is equal to any candidate, update that candidate's count.
// If count of a candidate reaches zero then replace that candidate with current element.
// If neither candidate matches and both counts are non zero, decrement the counts.
// After this, in second pass we check if the chosen candidates appear more than n/3 times in the array. If they do then include them in result array.
// Since any element than appears more than floor(n/3) times, will dominate over elements that appear less frequently. Whenever we encounter a different element, we decrement the count of both the candidates. This maintains at most two candidates in the array.

vector<int> findmajority(vector<int>& arr){
    int n = arr.size();
   //Take two elements and two count variable because at n/3 there is atmost 2 element and 2 count variables are there
   int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0;
    
   for(int ele : arr){
        if(ele1 == ele) cnt1++;
        else if(ele2 == ele) cnt2++;
        else if(cnt1 == 0){
            ele1 = ele;
            cnt1++;
        }
        else if(cnt2 == 0){
            ele2 = ele;
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
   }

   vector<int> res;
   //now element will be chooses so settle down in the array 
   //so now count the occurances so set cnt = 0;
   cnt1 = 0, cnt2 = 0;
   for(int ele : arr){
    if(ele1 == ele) cnt1++;
    if(ele2 == ele) cnt2++;
   }

   if(cnt1 > n/3) res.push_back(ele1);
   if(cnt2 > n/3 && ele1 != ele2) res.push_back(ele2);

   if(res.size()==2 && res[0] > res[1]) swap(res[0],res[1]);

   return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++){
        cin>>v[i];
    }
    vector<int> ans = findmajority(v);
    for(int i : ans){
        cout<<i<<" ";
    }
    return 0;
}
// 11
// 2 1 5 5 5 5 6 6 6 6 6