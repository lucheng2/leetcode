#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxsumofSubarray(vector<int>& arr) {
        int mx = max(0, arr[0]);
        for(int i=1; i<arr.size(); i++) {
            arr[i] = arr[i-1] >=0? arr[i-1]+arr[i]: arr[i];
            mx = max(mx, arr[i]);
        }
        return mx;
    }
};
