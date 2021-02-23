#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

// 数组集合A,分为A1 A2两个部分, 有
// sum(A1)-sum(A2)=S;
// sum(A) = sum(A1) + sum(A2)
// 推出: sum(A1) = (S+sum(A))/2 = V
// 转化为0-1背包问题的解的个数问题
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        for(auto n:nums)
            sum += n;
        if(sum<S ||(sum + S) % 2 == 1)
            return 0;
        int V = (sum+S)/2;
        int N = nums.size();
        vector<int> F(V+1, 0);
        F[0] = 1;
        for(int i=1; i<=N; ++i) {
            for(int j=V; j>= nums[i-1]; --j) {
                F[j] = F[j] + F[j-nums[i-1]];
            }
        }
        return F[V];
    }
};

int main() {
	
	return 0;
}
