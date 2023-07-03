#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int foundOnceNumber(vector<int>& arr, int k) {
        int bitSum[32];
        for(int i=0; i<32; i++) {
            int sum = 0;
            for(int j=0; j<arr.size(); j++) {
                sum += (arr[j]>>i) & 1;
            }
            bitSum[i] = sum;
        }
        int ans = 0;
        for(int i=0; i<32; i++) {
            if(bitSum[i] % k != 0)
                ans += 1 << i;
        }
        return ans;
    }
};
