
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
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(r>l){
            int m =(r+l)/2;
            if(nums[m]>nums[r]){
                l=m+1;
            }
            else{
                r=m;
            }
        }
        return nums[r];
        
    }
};