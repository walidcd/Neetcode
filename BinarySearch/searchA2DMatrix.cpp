
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
#define INF 1e8
int findLine(vector<vector<int>>& matrix, int target){
    int r=matrix.size()-1;
    int l=0;
    int c=matrix[0].size()-1;
    while(r>=l){
        int m=(r+l)/2;
        if(matrix[m][0]<=target&&matrix[m][c]>=target){
            return m;
        }
        else if(matrix[m][0]>target){
            r=m-1;
        }else if(matrix[m][c]<target){
            l=m+1;
        }
    }
    return -1;
}
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(findLine(matrix,target)==-1) return false ;
        int line=findLine(matrix,target);
        return binary_search(matrix[line].begin(),matrix[line].end(),target);
    }
};