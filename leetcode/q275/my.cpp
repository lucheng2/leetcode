#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    bool check(vector<int> & citations, int h) {
        int n = citations.size();
        return citations[n-h] >= h ? true: false;
    }
    int hIndex(vector<int>& citations) {
        int ans = 0;
        int low = 1, high = citations.size();
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(citations, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
