#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// time complexity O(n)
// Space Complexity O(n)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0;
        int r=nums.size()-1;
        while(r>=l){
            int m =(r+l)/2;
            if(nums[m]==target) return m;
            //right part sorted 
            if(nums[m]<nums[r]){
                if(target<nums[m]||target>nums[r]) {r=m-1;}
                else{l=m+1;}
            }else{
                //left part sorted
                if(target<nums[l]||target>nums[m]) {l=m+1;}
                else{r=m-1;}
            }
        }
        return -1;
    }
};