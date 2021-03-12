#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m -1;
        int p2 = n -1;
        int p = m+n-1;
        while(p1>=0 && p2>=0) {
            nums1[p--] = nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
        }
        if(p2>=0) {
            for(int i=0; i<=p2; ++i) 
                nums1[i] = nums2[i];
        }
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    s.merge(nums1, 3, nums2, 3);
	return 0;
}
