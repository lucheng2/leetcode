#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if(sum1<sum2) {
            swap(sum1, sum2);
            swap(nums1, nums2);
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1= nums1.size(), n2 = nums2.size();
        int i=n1-1, j=0;
        int count = 0;
        while(i>=0 && j<n2 && sum1 > sum2) {
            if(nums1[i] -1 > 6 - nums2[j]) {
                sum1 -= (nums1[i] -1);
                i--;
            } else {
                sum2 += (6 -nums2[j]);
                j++;
            }
            count ++;
        }
        while(i>=0 && sum1>sum2) {
            sum1 -= nums1[i] -1;
            i--;
            count ++;
        }
        while(j<n2 && sum1>sum2) {
            sum2 += 6 - nums2[j];
            j++;
            count++;
        }
        return sum1<=sum2? count: -1;

    }
};

int main() {
	
	return 0;
}
