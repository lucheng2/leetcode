#include<iostream>
#include<vector>

using namespace std;

/**
* 无论k有多大，胜利者都在arr数组中，尝试一次遍历。
* 遇见arr数组中的最大值之前都没有满足条件的胜利者，那么胜利者一定是这个最大值。
* 最多遍历一次就会遇见arr数组中的最大值，所以输掉的就不用再考虑。
**/

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int preNum = arr[0], winCount = 0, max = preNum;
        for (int i = 1; i < arr.size(); i++) {
            if (preNum > arr[i]) {
                winCount++;
            }
            else
            {
                max = preNum = arr[i];
                winCount = 1;
            }
            if (winCount >= k) {
                return preNum;
            }
        }
        return max;
    }
};

int main() {
    vector<int> arr = { 3,2,1 };
    Solution solution;
    int result = solution.getWinner(arr, 2);
    return 0;
}