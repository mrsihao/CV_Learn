#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <climits>
#include <cmath>
#include <stack>
#include <queue>
#include <list>
#include <opencv2/objdetect.hpp>
#include "lbplibrary.hpp"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        auto low = lower_bound(nums.begin(), nums.end(), target);
//        auto up = lower_bound(nums.begin(), nums.end(),target);
//    }
//};


class Solution2 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > sum(m, vector<int>(n, grid[0][0]));
        for (int i = 1; i < m; i++)
            sum[i][0] = sum[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++)
            sum[0][j] = sum[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                sum[i][j]  = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
        return sum[m - 1][n - 1];
    }
};

int BinSearch(vector<int> a, int low, int high, int val){// 若找到则返回相应位置，没找到就是比待查元素小一点的位置
    while(low<high){
        int mid=(low+high)/2;
        if(a[mid] == val )  return mid;
        else if(a[mid] > val) high=mid-1;
        else    low=mid+1;
    }
    if(low==0) return low;
    else return a[low] <= val ? low : low-1;
}

