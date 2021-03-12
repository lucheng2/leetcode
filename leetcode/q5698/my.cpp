#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for(auto n: nums) {
            sum += n;
        }
        long long sub = abs((long long) goal - sum);
        int ans = sub / limit; 
        if(sub % limit) 
            ans ++;
        return ans;
    }
};

int main() {
	
	return 0;
}
