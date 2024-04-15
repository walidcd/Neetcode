
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



int search(vector<int>& nums, int target) {
    int r=nums.size()-1;
    int l=0;
    while(r>=l){
        int m=(r+l)/2;
        if(nums[m]>target){
            r=m-1;
        } else if(nums[m]<target){
            l=m+1;
        }
        else{
            return m;
        }

    }
    return -1;
}
int calculateTime(vector<int> piles,int rate){
    int s=0;
    for(int i=0;i<piles.size();i++){
        s+=(ceil)((double)piles[i]/(double)rate);
    }
    return s;
}


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxel=*max_element(piles.begin(), piles.end());
        int result=0;
        int r=maxel;
        int l=1;
        int m;
        if(piles.size()==1){
            return piles[0]>=h?(ceil((double)piles[0]/(double)h)):1;
        }
        while(r>=l){
            m =(r+l)/2;
            if(calculateTime(piles,m)==h){
                result=m;
                r=m;
            } 
            else if(calculateTime(piles,m)>h){
                l=m+1;
            }else if(calculateTime(piles,m)<h){
                r=m;
                result=m;
            }
            if(r==l) return r;
        }
        return result;
    }
};