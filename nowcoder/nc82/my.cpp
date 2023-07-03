#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> ans;
        int n = num.size();
        if(n==0 || size==0 || n < size)
            return ans;
        deque<int> dq;
        for(int i=0; i<n; i++) {
            while(!dq.empty() && num[dq.back()] < num[i])
                dq.pop_back();
            dq.push_back(i);
            if(dq.front() + size <= i)
                dq.pop_front();
            if(i+1 >= size)
                ans.push_back(num[dq.front()]);
        }
        return ans;
    }
};
