#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hm;
        stack<int> stk;
        for(int i: nums2) {
            while(!stk.empty() && stk.top() < i) {
                hm[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()) {
            hm[stk.top()] = -1;
            stk.pop();
        }
        vector<int> ans;
        for(int i: nums1) {
            ans.push_back(hm[i]);
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
