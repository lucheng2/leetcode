#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

// S分为A, B两个集合, 有sum(A)=sum(B); sum(A)+sum(B)=sum(S); 推出sum(A)=sum(S)/2;
// 可以转化为容量为sum(S)/2的0-1背包可行性问题
// 定义状态: F[i][j]表示前i个数中选取若干个数的和, 恰好为j, 是否可行.
class Solution {
public:
    bool F[201][3000];
    bool canPartition(vector<int>& nums) {
        int V = 0;
        for(auto n: nums)
            V += n;
        if(V%2==1)
            return false;
        V = V/2;
        int N = nums.size();
        memset(F, false, sizeof(F));
        for(int i=0; i<=N; ++i) {
            F[i][0] = true;
        }
        for(int i=1; i<=N; ++i) {
            for(int j=nums[i-1]; j<=V; ++j) {
                F[i][j] = F[i-1][j] || F[i-1][j-nums[i-1]];
            }
        }
        return F[N][V];
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,5};
    bool ans = s.canPartition(nums);
    printf("%d\n", ans);    
	return 0;
}
