#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int l=0, r=data.size()-1, mid;
        while(l<=r) {
            mid = l + (r-l)/2;
            if(data[mid] == k)
                break;
            if(data[mid] < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        if(l>r)
            return 0;
        l = mid, r=mid;
        while(l>=0 && data[l]==k)
            l--;
        while(r<data.size() && data[r]==k)
            r++;
        return r-l-1;
    }
};
